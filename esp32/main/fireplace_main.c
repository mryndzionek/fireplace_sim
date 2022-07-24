/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"

#include "pwm_audio.h"

#include "faust_dsp.h"

static const char *TAG = "fireplace";

#define BLINK_GPIO (2)
#define SAMPLERATE (28000)

#define OUT_SIZE (SAMPLERATE / 4)
#define TIME_BUDGET_MS (1000UL / 4)

static QueueHandle_t dacInput;

static void configure_led(void)
{
    gpio_reset_pin(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

static void i2s_dac_data_scale(int16_t *d_buff, const float *const s_buff, uint32_t len)
{
    for (int i = 0; i < len; i++)
    {
        d_buff[i] = (int16_t)(s_buff[i] * __INT16_MAX__);
    }
}

void dac_tx_task(void *arg)
{
    int16_t *data;
    size_t bytes_written;
    esp_err_t err;
    BaseType_t ret;

    for (;;)
    {
        if (xQueuePeek(dacInput, &data, portMAX_DELAY))
        {
            err = pwm_audio_write((uint8_t *)data, 2 * OUT_SIZE, &bytes_written, portMAX_DELAY);
            assert(err == ESP_OK);
            assert(bytes_written == 2 * OUT_SIZE);
            ret = xQueueReceive(dacInput, &data, 0);
            assert(ret == pdTRUE);
        }
    }
}

void app_main(void)
{
    int i = 0;
    static FAUSTFLOAT outputBuffer[OUT_SIZE];
    const FAUSTFLOAT *buffer = outputBuffer;

    static int16_t i2s_write_buff[2][OUT_SIZE];

    uint32_t pre;
    esp_err_t err;

    configure_led();

    pwm_audio_config_t pac;
    pac.duty_resolution = LEDC_TIMER_10_BIT;
    pac.gpio_num_left = 25;
    pac.ledc_channel_left = LEDC_CHANNEL_0;
    pac.gpio_num_right = -1;
    pac.ledc_channel_right = LEDC_CHANNEL_1;
    pac.ledc_timer_sel = LEDC_TIMER_0;
    pac.tg_num = TIMER_GROUP_0;
    pac.timer_num = TIMER_0;
    pac.ringbuf_len = 1024 * 8;
    pwm_audio_init(&pac);

    err = pwm_audio_set_param(SAMPLERATE, 16, 1);
    assert(err == ESP_OK);
    err = pwm_audio_set_volume(4);
    assert(err == ESP_OK);
    err = pwm_audio_start();
    assert(err == ESP_OK);

    dacInput = xQueueCreate(1, sizeof(int16_t *));
    assert(dacInput);

    BaseType_t res = xTaskCreate(dac_tx_task, "dac_tx_task", 1024 * 2, NULL, tskIDLE_PRIORITY + 1, NULL);
    assert(res == pdPASS);

    mydsp_t *dsp = newmydsp(SAMPLERATE);
    assert(dsp);
    wet(dsp, true);

    compute(dsp, OUT_SIZE, NULL, (FAUSTFLOAT **)&buffer);
    i2s_dac_data_scale(i2s_write_buff[i], buffer, OUT_SIZE);

    while (1)
    {
        int16_t *p = i2s_write_buff[i];
        res = xQueueSend(dacInput, &p, portMAX_DELAY);
        assert(res == pdTRUE);
        gpio_set_level(BLINK_GPIO, 1);
        pre = portTICK_PERIOD_MS * xTaskGetTickCount();
        compute(dsp, OUT_SIZE, NULL, (FAUSTFLOAT **)&buffer);
        i ^= 1;
        i2s_dac_data_scale(i2s_write_buff[i], buffer, OUT_SIZE);
        pre = (portTICK_PERIOD_MS * xTaskGetTickCount()) - pre;
        gpio_set_level(BLINK_GPIO, 0);
        ESP_LOGI(TAG, "Audio generation took %d ms (%lu %%)", pre, (100 * pre) / TIME_BUDGET_MS);
    }
}

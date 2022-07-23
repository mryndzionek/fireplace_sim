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
#include "driver/gpio.h"
#include "driver/i2s.h"
#include "esp_log.h"
#include "sdkconfig.h"

#include "faust_dsp.h"

static const char *TAG = "fireplace";

#define BLINK_GPIO (2)
#define SAMPLERATE (44100)
#define OUT_SIZE (SAMPLERATE / 4)
#define TIME_BUDGET_MS (1000UL / 4)

static QueueHandle_t dacInput;

static void configure_led(void)
{
    ESP_LOGI(TAG, "Example configured to blink GPIO LED!");
    gpio_reset_pin(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

static void i2s_init(void)
{
    int i2s_num = 0;
    i2s_config_t i2s_config = {
        .mode = I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN,
        .sample_rate = SAMPLERATE,
        .bits_per_sample = 16,
        .communication_format = I2S_COMM_FORMAT_STAND_MSB,
        .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,
        .intr_alloc_flags = 0,
        .dma_buf_count = 2,
        .dma_buf_len = 1024,
        .use_apll = 1,
    };
    // install and start i2s driver
    i2s_driver_install(i2s_num, &i2s_config, 0, NULL);
    // init DAC pad
    i2s_set_dac_mode(I2S_DAC_CHANNEL_BOTH_EN);
}

static int i2s_dac_data_scale(uint8_t *d_buff, float *s_buff, uint32_t len)
{
    uint32_t j = 0;

    for (int i = 0; i < len; i++)
    {
        d_buff[j++] = 0;
        d_buff[j++] = (uint8_t)((s_buff[i] * 128) + 128);
    }
    return (len * 2);
}

void dac_tx_task(void *arg)
{
    static uint8_t i2s_write_buff[2 * OUT_SIZE];

    float *in_buff;
    size_t bytes_written;
    esp_err_t err;
    int i2s_wr_len;

    for (;;)
    {
        if (xQueueReceive(dacInput, &in_buff, portMAX_DELAY))
        {
            i2s_wr_len = i2s_dac_data_scale(i2s_write_buff, in_buff, OUT_SIZE);
            err = i2s_write(0, i2s_write_buff, i2s_wr_len, &bytes_written, portMAX_DELAY);
            assert(err == ESP_OK);
        }
    }
}

void app_main(void)
{
    static FAUSTFLOAT outputBuffer[2][OUT_SIZE];

    uint32_t pre;
    int i = 0;

    configure_led();
    i2s_init();

    dacInput = xQueueCreate(1, sizeof(float *));
    assert(dacInput);

    BaseType_t res = xTaskCreate(dac_tx_task, "dac_tx_task", 1024 * 2, NULL, tskIDLE_PRIORITY + 1, NULL);
    assert(res == pdPASS);

    mydsp_t *dsp = newmydsp(SAMPLERATE);
    assert(dsp);

    FAUSTFLOAT *buffer = (FAUSTFLOAT *)outputBuffer[i];
    compute(dsp, OUT_SIZE, NULL, (FAUSTFLOAT **)&buffer);

    while (1)
    {
        res = xQueueSend(dacInput, &buffer, portMAX_DELAY);
        assert(res == pdTRUE);
        i ^= 1;
        buffer = (FAUSTFLOAT *)outputBuffer[i];
        gpio_set_level(BLINK_GPIO, 1);
        pre = portTICK_PERIOD_MS * xTaskGetTickCount();
        compute(dsp, OUT_SIZE, NULL, (FAUSTFLOAT **)&buffer);
        pre = (portTICK_PERIOD_MS * xTaskGetTickCount()) - pre;
        gpio_set_level(BLINK_GPIO, 0);
        ESP_LOGI(TAG, "Audio generation took %d ms (%lu %%)", pre, (100 * pre) / TIME_BUDGET_MS);
    }
}

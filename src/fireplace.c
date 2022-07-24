#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <stdbool.h>
#include <argp.h>

#include <rtaudio/rtaudio_c.h>

#include "faust_dsp.h"

#define DEFAULT_SAMPLERATE (44100)
#define BUFFER_S (1)

struct arguments
{
    char *args[1];
    bool wet;
    unsigned int samplerate;
};

static char doc[] =
    "fireplace -- a fireplace sound simulator";

static char args_doc[] = "";

static struct argp_option options[] = {
    {"wet", 'w', 0, 0, "Popping sound of wet wood"},
    {"samplerate", 's', "SR", 0, "Output sample rate"},
    {0}};

static error_t
parse_opt(int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;

    switch (key)
    {
    case 'w':
        arguments->wet = true;
        break;
    case 's':
        arguments->samplerate = atoll(arg);
        if (arguments->samplerate < 20000)
        {
            fprintf(stderr, "Please use correct sample rate (>= 20000)\n");
            argp_usage(state);
        }
        break;

    case ARGP_KEY_ARG:
        if (state->arg_num >= 0)
            argp_usage(state);

        arguments->args[state->arg_num] = arg;
        break;

    case ARGP_KEY_END:
        if (state->arg_num < 0)
            argp_usage(state);
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc};

static int
audio_cb(void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
         double stream_time, rtaudio_stream_status_t status, void *data)
{
    mydsp_t *dsp = data;
    FAUSTFLOAT *buffer = (FAUSTFLOAT *)outputBuffer;

    // fprintf(stderr, "audio callback\n");

    if (status)
    {
        fprintf(stderr, "Stream underflow detected!");
    }

    compute(dsp, nBufferFrames, NULL, (FAUSTFLOAT **)&buffer);

    return 0;
}

static void error_cb(rtaudio_error_t err, const char *msg)
{
    fprintf(stderr, "Error type: %d message: %s\n", err, msg);
}

int main(int argc, char *argv[])
{

    struct arguments arguments;

    arguments.wet = false;
    arguments.samplerate = DEFAULT_SAMPLERATE;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    fprintf(stderr, "Using samplerate: %d\n", arguments.samplerate);
    unsigned int bufferFrames = arguments.samplerate * BUFFER_S;

    const rtaudio_api_t api = rtaudio_compiled_api_by_name("pulse");
    fprintf(stderr, "RTAudio API: %s\n", rtaudio_api_name(api));

    rtaudio_t dac = rtaudio_create(api);

    int n = rtaudio_device_count(dac);

    if (n == 0)
    {
        fprintf(stderr, "No audio devices available\n");
        exit(EXIT_FAILURE);
    }
    else if (n == 1)
    {
        fprintf(stderr, "There is %d audio device available\n", n);
    }
    else
    {
        fprintf(stderr, "There are %d audio devices available:\n", n);
    }

    int dev = rtaudio_get_default_output_device(dac);

    for (int i = 0; i < n; i++)
    {
        rtaudio_device_info_t info = rtaudio_get_device_info(dac, i);
        if (info.probed)
        {
            fprintf(stderr, "\t\"%s\"%s\n", info.name, dev == i ? " (default)" : "");
        }
        else
        {
            fprintf(stderr, "Failed to read info from audio device: %d\n", i);
        }
    }

    rtaudio_show_warnings(dac, true);

    mydsp_t *dsp = newmydsp(arguments.samplerate);
    assert(dsp);
    wet(dsp, arguments.wet);

    rtaudio_stream_parameters_t o_params = {
        .device_id = rtaudio_get_default_output_device(dac),
        .first_channel = 0,
        .num_channels = getNumOutputs(dsp)};

    rtaudio_stream_options_t options = {
        .flags = RTAUDIO_FLAGS_HOG_DEVICE | RTAUDIO_FLAGS_MINIMIZE_LATENCY | RTAUDIO_FLAGS_NONINTERLEAVED};

    rtaudio_error_t err = rtaudio_open_stream(dac, &o_params, NULL,
                                              sizeof(FAUSTFLOAT) == 4 ? RTAUDIO_FORMAT_FLOAT32 : RTAUDIO_FORMAT_FLOAT64,
                                              arguments.samplerate, &bufferFrames, &audio_cb,
                                              (void *)dsp, &options,
                                              &error_cb);
    assert(err == 0);

    err = rtaudio_start_stream(dac);
    assert(err == 0);

    char c;

    fprintf(stderr, "Type 'q' to quit\n");
    while ((c = getchar()) && (c != 'q'))
    {
        usleep(100000);
    }

    fprintf(stderr, "Stopping audio streams\n");

    err = rtaudio_stop_stream(dac);
    assert(err == 0);
    if (rtaudio_is_stream_open(dac))
    {
        rtaudio_close_stream(dac);
    }

    deletemydsp(dsp);

    fprintf(stderr, "Exiting\n");
    exit(EXIT_SUCCESS);
}

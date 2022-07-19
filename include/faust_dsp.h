#ifndef __mydsp_H__
#define __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct mydsp mydsp_t;

    mydsp_t *newmydsp(int sample_rate);
    void deletemydsp(mydsp_t *dsp);

    int getSampleRate(mydsp_t *dsp);
    int getNumInputs(mydsp_t *dsp);
    int getNumOutputs(mydsp_t *dsp);
    void compute(mydsp_t *dsp, int count, FAUSTFLOAT **RESTRICT inputs, FAUSTFLOAT **RESTRICT outputs);

#ifdef __cplusplus
}
#endif

#endif
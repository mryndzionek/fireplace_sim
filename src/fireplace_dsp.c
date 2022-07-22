/* ------------------------------------------------------------
name: "fireplace"
Code generated with Faust 2.41.1 (https://faust.grame.fr)
Compilation options: -lang c -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#include <math.h>
#include <stdint.h>
#include <stdlib.h>

#include "faust_dsp.h"

typedef struct
{
	int iVec4[2];
	int iRec21[2];
} mydspSIG0;

static mydspSIG0 *newmydspSIG0() { return (mydspSIG0 *)calloc(1, sizeof(mydspSIG0)); }
static void deletemydspSIG0(mydspSIG0 *dsp) { free(dsp); }

static void classInitmydsp(int sample_rate);
static void initmydsp(mydsp_t *dsp, int sample_rate);

static void instanceInitmydspSIG0(mydspSIG0 *dsp, int sample_rate)
{
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1)
		{
			dsp->iVec4[l23] = 0;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 2; l24 = l24 + 1)
		{
			dsp->iRec21[l24] = 0;
		}
	}
}

static void fillmydspSIG0(mydspSIG0 *dsp, int count, float *table)
{
	/* C99 loop */
	{
		int i1;
		for (i1 = 0; i1 < count; i1 = i1 + 1)
		{
			dsp->iVec4[0] = 1;
			dsp->iRec21[0] = (dsp->iVec4[1] + dsp->iRec21[1]) % 4096;
			table[i1] = sinf(0.00153398083f * (float)(dsp->iRec21[0]));
			dsp->iVec4[1] = dsp->iVec4[0];
			dsp->iRec21[1] = dsp->iRec21[0];
		}
	}
}

static float mydsp_faustpower2_f(float value)
{
	return value * value;
}
static float ftbl0mydspSIG0[4096];

#ifndef FAUSTCLASS
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__
#define exp10f __exp10f
#define exp10 __exp10
#endif

struct mydsp
{
	int fSampleRate;
	float fConst4;
	float fConst5;
	int iVec0[2];
	int iRec2[2];
	float fVec1[2];
	float fConst6;
	float fRec1[2];
	float fConst7;
	float fConst8;
	float fConst9;
	float fRec0[3];
	float fConst13;
	float fConst17;
	float fConst18;
	float fConst20;
	float fConst21;
	float fRec9[2];
	float fRec10[2];
	float fRec8[2];
	float fRec7[2];
	float fRec6[2];
	float fRec5[2];
	float fRec4[2];
	float fRec3[2];
	float fConst23;
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec12[2];
	float fConst28;
	float fConst29;
	float fConst30;
	float fRec11[3];
	float fConst31;
	float fConst32;
	float fConst34;
	float fConst36;
	float fConst38;
	float fConst39;
	float fConst40;
	float fRec16[2];
	float fVec2[2];
	float fRec17[2];
	float fVec3[2];
	float fRec18[2];
	float fConst41;
	float fRec15[2];
	float fConst43;
	float fConst44;
	float fRec20[2];
	float fConst45;
	float fConst46;
	float fConst48;
	float fConst49;
	float fRec19[3];
	float fConst50;
	float fRec22[2];
	float fVec5[2];
	float fConst51;
	float fConst52;
	float fRec14[2];
	float fConst53;
	float fConst54;
	float fRec13[3];
	float fConst55;
	float fConst56;
	float fRec26[2];
	float fVec6[2];
	float fRec27[2];
	float fVec7[2];
	float fRec28[2];
	float fRec25[2];
	float fConst57;
	float fRec29[2];
	float fVec8[2];
	float fRec24[2];
	float fRec23[3];
	float fConst58;
	float fRec33[2];
	float fVec9[2];
	float fRec34[2];
	float fVec10[2];
	float fRec35[2];
	float fRec32[2];
	float fConst59;
	float fRec36[2];
	float fVec11[2];
	float fRec31[2];
	float fRec30[3];
	float fVec12[2];
	float fRec38[2];
	float fRec37[3];
	float fConst60;
	float fRec40[2];
	float fRec39[3];
	float fConst61;
};

mydsp_t *newmydsp(int sample_rate)
{
	mydsp_t *dsp = (mydsp_t *)calloc(1, sizeof(mydsp_t));
	if (dsp)
	{
		initmydsp(dsp, sample_rate);
	}
	return dsp;
}

void deletemydsp(mydsp_t *dsp)
{
	free(dsp);
}

int getSampleRate(mydsp_t *dsp)
{
	return dsp->fSampleRate;
}

int getNumInputs(mydsp_t *dsp)
{
	return 0;
}
int getNumOutputs(mydsp_t *dsp)
{
	return 1;
}

static void classInitmydsp(int sample_rate)
{
	mydspSIG0 *sig0 = newmydspSIG0();
	instanceInitmydspSIG0(sig0, sample_rate);
	fillmydspSIG0(sig0, 4096, ftbl0mydspSIG0);
	deletemydspSIG0(sig0);
}

static void instanceResetUserInterfacemydsp(mydsp_t *dsp)
{
}

static void instanceClearmydsp(mydsp_t *dsp)
{
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1)
		{
			dsp->iVec0[l0] = 0;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1)
		{
			dsp->iRec2[l1] = 0;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1)
		{
			dsp->fVec1[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1)
		{
			dsp->fRec1[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 3; l4 = l4 + 1)
		{
			dsp->fRec0[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1)
		{
			dsp->fRec9[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1)
		{
			dsp->fRec10[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1)
		{
			dsp->fRec8[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1)
		{
			dsp->fRec7[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1)
		{
			dsp->fRec6[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1)
		{
			dsp->fRec5[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1)
		{
			dsp->fRec4[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 2; l12 = l12 + 1)
		{
			dsp->fRec3[l12] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l13;
		for (l13 = 0; l13 < 2; l13 = l13 + 1)
		{
			dsp->fRec12[l13] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l14;
		for (l14 = 0; l14 < 3; l14 = l14 + 1)
		{
			dsp->fRec11[l14] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l15;
		for (l15 = 0; l15 < 2; l15 = l15 + 1)
		{
			dsp->fRec16[l15] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l16;
		for (l16 = 0; l16 < 2; l16 = l16 + 1)
		{
			dsp->fVec2[l16] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l17;
		for (l17 = 0; l17 < 2; l17 = l17 + 1)
		{
			dsp->fRec17[l17] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l18;
		for (l18 = 0; l18 < 2; l18 = l18 + 1)
		{
			dsp->fVec3[l18] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l19;
		for (l19 = 0; l19 < 2; l19 = l19 + 1)
		{
			dsp->fRec18[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1)
		{
			dsp->fRec15[l20] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l21;
		for (l21 = 0; l21 < 2; l21 = l21 + 1)
		{
			dsp->fRec20[l21] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l22;
		for (l22 = 0; l22 < 3; l22 = l22 + 1)
		{
			dsp->fRec19[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1)
		{
			dsp->fRec22[l25] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1)
		{
			dsp->fVec5[l26] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1)
		{
			dsp->fRec14[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 3; l28 = l28 + 1)
		{
			dsp->fRec13[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1)
		{
			dsp->fRec26[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 2; l30 = l30 + 1)
		{
			dsp->fVec6[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1)
		{
			dsp->fRec27[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1)
		{
			dsp->fVec7[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1)
		{
			dsp->fRec28[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1)
		{
			dsp->fRec25[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 2; l35 = l35 + 1)
		{
			dsp->fRec29[l35] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l36;
		for (l36 = 0; l36 < 2; l36 = l36 + 1)
		{
			dsp->fVec8[l36] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l37;
		for (l37 = 0; l37 < 2; l37 = l37 + 1)
		{
			dsp->fRec24[l37] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l38;
		for (l38 = 0; l38 < 3; l38 = l38 + 1)
		{
			dsp->fRec23[l38] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l39;
		for (l39 = 0; l39 < 2; l39 = l39 + 1)
		{
			dsp->fRec33[l39] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l40;
		for (l40 = 0; l40 < 2; l40 = l40 + 1)
		{
			dsp->fVec9[l40] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l41;
		for (l41 = 0; l41 < 2; l41 = l41 + 1)
		{
			dsp->fRec34[l41] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l42;
		for (l42 = 0; l42 < 2; l42 = l42 + 1)
		{
			dsp->fVec10[l42] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l43;
		for (l43 = 0; l43 < 2; l43 = l43 + 1)
		{
			dsp->fRec35[l43] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l44;
		for (l44 = 0; l44 < 2; l44 = l44 + 1)
		{
			dsp->fRec32[l44] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l45;
		for (l45 = 0; l45 < 2; l45 = l45 + 1)
		{
			dsp->fRec36[l45] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l46;
		for (l46 = 0; l46 < 2; l46 = l46 + 1)
		{
			dsp->fVec11[l46] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l47;
		for (l47 = 0; l47 < 2; l47 = l47 + 1)
		{
			dsp->fRec31[l47] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l48;
		for (l48 = 0; l48 < 3; l48 = l48 + 1)
		{
			dsp->fRec30[l48] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l49;
		for (l49 = 0; l49 < 2; l49 = l49 + 1)
		{
			dsp->fVec12[l49] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l50;
		for (l50 = 0; l50 < 2; l50 = l50 + 1)
		{
			dsp->fRec38[l50] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l51;
		for (l51 = 0; l51 < 3; l51 = l51 + 1)
		{
			dsp->fRec37[l51] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l52;
		for (l52 = 0; l52 < 2; l52 = l52 + 1)
		{
			dsp->fRec40[l52] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l53;
		for (l53 = 0; l53 < 3; l53 = l53 + 1)
		{
			dsp->fRec39[l53] = 0.0f;
		}
	}
}

static void instanceConstantsmydsp(mydsp_t *dsp, int sample_rate)
{
	dsp->fSampleRate = sample_rate;
	float fConst0 = fminf(192000.0f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	float fConst1 = tanf(1570.79639f / fConst0);
	float fConst2 = 1.0f / fConst1;
	float fConst3 = (fConst2 + 1.0f) / fConst1 + 1.0f;
	dsp->fConst4 = 0.200000003f / fConst3;
	dsp->fConst5 = 1.0f / (fConst2 + 1.0f);
	dsp->fConst6 = 1.0f - fConst2;
	dsp->fConst7 = 1.0f / fConst3;
	dsp->fConst8 = (fConst2 + -1.0f) / fConst1 + 1.0f;
	dsp->fConst9 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fConst1));
	float fConst10 = tanf(9424.77832f / fConst0);
	float fConst11 = 1.0f / fConst10;
	float fConst12 = (fConst11 + 1.0f) / fConst10 + 1.0f;
	dsp->fConst13 = 0.100000001f / fConst12;
	float fConst14 = tanf(3141.59277f / fConst0);
	float fConst15 = 1.0f / fConst14;
	float fConst16 = fConst15 + 1.0f;
	dsp->fConst17 = 1.0f / fConst16;
	dsp->fConst18 = 1.0f - fConst15;
	float fConst19 = 6283.18555f / fConst0;
	dsp->fConst20 = sinf(fConst19);
	dsp->fConst21 = cosf(fConst19);
	float fConst22 = mydsp_faustpower2_f(fConst10);
	dsp->fConst23 = 1.0f / fConst22;
	float fConst24 = fConst11 + 1.0f;
	dsp->fConst25 = 1.0f / (fConst10 * fConst24);
	dsp->fConst26 = 0.0f - dsp->fConst25;
	dsp->fConst27 = (1.0f - fConst11) / fConst24;
	dsp->fConst28 = 1.0f / fConst12;
	dsp->fConst29 = (fConst11 + -1.0f) / fConst10 + 1.0f;
	dsp->fConst30 = 2.0f * (1.0f - dsp->fConst23);
	dsp->fConst31 = 0.0f - 2.0f / fConst22;
	dsp->fConst32 = 1.0f / ((fConst15 + 1.0f) / fConst14 + 1.0f);
	float fConst33 = mydsp_faustpower2_f(fConst14);
	dsp->fConst34 = 1.0f / fConst33;
	float fConst35 = tanf(31415.9258f / fConst0);
	dsp->fConst36 = 1.0f / fConst35;
	float fConst37 = (dsp->fConst36 + 1.0f) / fConst35 + 1.0f;
	dsp->fConst38 = 0.769999981f / fConst37;
	dsp->fConst39 = 1.0f / (fConst14 * fConst16);
	dsp->fConst40 = 5.0f / fConst0;
	dsp->fConst41 = 1.0f / fConst0;
	float fConst42 = dsp->fConst36 + 1.0f;
	dsp->fConst43 = 1.0f / fConst42;
	dsp->fConst44 = 1.0f - dsp->fConst36;
	dsp->fConst45 = 1.0f / fConst37;
	dsp->fConst46 = (dsp->fConst36 + -1.0f) / fConst35 + 1.0f;
	float fConst47 = mydsp_faustpower2_f(fConst35);
	dsp->fConst48 = 1.0f / fConst47;
	dsp->fConst49 = 2.0f * (1.0f - dsp->fConst48);
	dsp->fConst50 = 10.0f / fConst0;
	dsp->fConst51 = 0.0f - dsp->fConst39;
	dsp->fConst52 = dsp->fConst18 / fConst16;
	dsp->fConst53 = (fConst15 + -1.0f) / fConst14 + 1.0f;
	dsp->fConst54 = 2.0f * (1.0f - dsp->fConst34);
	dsp->fConst55 = 0.0f - 2.0f / fConst33;
	dsp->fConst56 = 0.5f / fConst0;
	dsp->fConst57 = 100.0f / fConst0;
	dsp->fConst58 = 0.300000012f / fConst0;
	dsp->fConst59 = 166.666672f / fConst0;
	dsp->fConst60 = 0.0f - 1.0f / (fConst35 * fConst42);
	dsp->fConst61 = 0.0f - 2.0f / fConst47;
}

static void instanceInitmydsp(mydsp_t *dsp, int sample_rate)
{
	instanceConstantsmydsp(dsp, sample_rate);
	instanceResetUserInterfacemydsp(dsp);
	instanceClearmydsp(dsp);
}

static void initmydsp(mydsp_t *dsp, int sample_rate)
{
	classInitmydsp(sample_rate);
	instanceInitmydsp(dsp, sample_rate);
}

void compute(mydsp_t *dsp, int count, FAUSTFLOAT **RESTRICT inputs, FAUSTFLOAT **RESTRICT outputs)
{
	FAUSTFLOAT *output0 = outputs[0];
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1)
		{
			dsp->iVec0[0] = 1;
			dsp->iRec2[0] = 1103515245 * dsp->iRec2[1] + 12345;
			float fTemp0 = (float)(dsp->iRec2[0]);
			dsp->fVec1[0] = fTemp0;
			float fTemp1 = 4.65661287e-10f * (fTemp0 + dsp->fVec1[1]);
			dsp->fRec1[0] = dsp->fConst5 * (fTemp1 - dsp->fConst6 * dsp->fRec1[1]);
			dsp->fRec0[0] = dsp->fRec1[0] - dsp->fConst7 * (dsp->fConst8 * dsp->fRec0[2] + dsp->fConst9 * dsp->fRec0[1]);
			dsp->fRec9[0] = dsp->fConst20 * dsp->fRec10[1] + dsp->fConst21 * dsp->fRec9[1];
			dsp->fRec10[0] = ((float)(1 - dsp->iVec0[1]) + dsp->fConst21 * dsp->fRec10[1]) - dsp->fConst20 * dsp->fRec9[1];
			int iTemp2 = (dsp->fRec9[1] <= 0.0f) & (dsp->fRec9[0] > 0.0f);
			dsp->fRec8[0] = dsp->fRec8[1] * (float)(1 - iTemp2) + 4.65661287e-10f * fTemp0 * (float)(iTemp2);
			dsp->fRec7[0] = 0.0f - dsp->fConst17 * (dsp->fConst18 * dsp->fRec7[1] - (dsp->fRec8[0] + dsp->fRec8[1]));
			dsp->fRec6[0] = 0.0f - dsp->fConst17 * (dsp->fConst18 * dsp->fRec6[1] - (dsp->fRec7[0] + dsp->fRec7[1]));
			dsp->fRec5[0] = 0.0f - dsp->fConst17 * (dsp->fConst18 * dsp->fRec5[1] - (dsp->fRec6[0] + dsp->fRec6[1]));
			dsp->fRec4[0] = 0.0f - dsp->fConst17 * (dsp->fConst18 * dsp->fRec4[1] - (dsp->fRec5[0] + dsp->fRec5[1]));
			dsp->fRec3[0] = 0.0f - dsp->fConst17 * (dsp->fConst18 * dsp->fRec3[1] - (dsp->fRec4[0] + dsp->fRec4[1]));
			dsp->fRec12[0] = 4.65661287e-10f * (dsp->fConst25 * fTemp0 + dsp->fConst26 * dsp->fVec1[1]) - dsp->fConst27 * dsp->fRec12[1];
			dsp->fRec11[0] = dsp->fRec12[0] - dsp->fConst28 * (dsp->fConst29 * dsp->fRec11[2] + dsp->fConst30 * dsp->fRec11[1]);
			float fTemp3 = dsp->fConst4 * (dsp->fRec0[2] + dsp->fRec0[0] + 2.0f * dsp->fRec0[1]) + dsp->fConst13 * mydsp_faustpower2_f(dsp->fRec3[0]) * (dsp->fConst23 * dsp->fRec11[0] + dsp->fConst31 * dsp->fRec11[1] + dsp->fConst23 * dsp->fRec11[2]);
			dsp->fRec16[0] = dsp->fConst40 + dsp->fRec16[1] - floorf(dsp->fConst40 + dsp->fRec16[1]);
			float fTemp4 = dsp->fRec16[0] - dsp->fRec16[1];
			dsp->fVec2[0] = fTemp4;
			int iTemp5 = (dsp->fVec2[1] <= 0.0f) & (fTemp4 > 0.0f);
			dsp->fRec17[0] = dsp->fRec17[1] * (float)(1 - iTemp5) + 4.65661287e-10f * fTemp0 * (float)(iTemp5);
			float fTemp6 = 0.5f * (dsp->fRec17[0] + 1.0f);
			float fTemp7 = dsp->fVec1[1] * (float)((dsp->fRec16[0] >= fTemp6) * (dsp->fRec16[1] < fTemp6));
			dsp->fVec3[0] = fTemp7;
			int iTemp8 = 4.65661287e-10f * fTemp7 > 0.0f;
			int iTemp9 = iTemp8;
			int iTemp10 = (4.65661287e-10f * dsp->fVec3[1] <= 0.0f) & iTemp8;
			float fTemp11 = fabsf(4.65661287e-10f * fTemp0);
			dsp->fRec18[0] = dsp->fRec18[1] * (float)(1 - iTemp10) + fTemp11 * (float)(iTemp10);
			float fThen0 = 0.300000012f * dsp->fRec18[0] + 0.100000001f;
			float fTemp12 = 0.144717798f * ((iTemp9) ? 0.00100000005f : fThen0);
			int iTemp13 = fabsf(fTemp12) < 1.1920929e-07f;
			float fThen2 = expf(0.0f - dsp->fConst41 / ((iTemp13) ? 1.0f : fTemp12));
			float fTemp14 = ((iTemp13) ? 0.0f : fThen2);
			float fElse3 = (float)(iTemp8);
			dsp->fRec15[0] = (1.0f - fTemp14) * ((iTemp9) ? fElse3 : 0.0f) + fTemp14 * dsp->fRec15[1];
			dsp->fRec20[0] = dsp->fConst43 * (fTemp1 - dsp->fConst44 * dsp->fRec20[1]);
			dsp->fRec19[0] = dsp->fRec20[0] - dsp->fConst45 * (dsp->fConst46 * dsp->fRec19[2] + dsp->fConst49 * dsp->fRec19[1]);
			float fTemp15 = dsp->fRec19[2] + dsp->fRec19[0] + 2.0f * dsp->fRec19[1];
			dsp->fRec22[0] = dsp->fConst50 + dsp->fRec22[1] - floorf(dsp->fConst50 + dsp->fRec22[1]);
			float fTemp16 = dsp->fRec15[0] * fTemp15 * ftbl0mydspSIG0[(int)(4096.0f * dsp->fRec22[0])];
			dsp->fVec5[0] = fTemp16;
			dsp->fRec14[0] = dsp->fConst38 * (dsp->fConst39 * fTemp16 + dsp->fConst51 * dsp->fVec5[1]) - dsp->fConst52 * dsp->fRec14[1];
			dsp->fRec13[0] = dsp->fRec14[0] - dsp->fConst32 * (dsp->fConst53 * dsp->fRec13[2] + dsp->fConst54 * dsp->fRec13[1]);
			dsp->fRec26[0] = dsp->fConst56 + dsp->fRec26[1] - floorf(dsp->fConst56 + dsp->fRec26[1]);
			float fTemp17 = dsp->fRec26[0] - dsp->fRec26[1];
			dsp->fVec6[0] = fTemp17;
			int iTemp18 = (dsp->fVec6[1] <= 0.0f) & (fTemp17 > 0.0f);
			dsp->fRec27[0] = dsp->fRec27[1] * (float)(1 - iTemp18) + 4.65661287e-10f * fTemp0 * (float)(iTemp18);
			float fTemp19 = 0.5f * (dsp->fRec27[0] + 1.0f);
			float fTemp20 = dsp->fVec1[1] * (float)((dsp->fRec26[0] >= fTemp19) * (dsp->fRec26[1] < fTemp19));
			dsp->fVec7[0] = fTemp20;
			int iTemp21 = 4.65661287e-10f * fTemp20 > 0.0f;
			int iTemp22 = iTemp21;
			int iTemp23 = (4.65661287e-10f * dsp->fVec7[1] <= 0.0f) & iTemp21;
			dsp->fRec28[0] = dsp->fRec28[1] * (float)(1 - iTemp23) + fTemp11 * (float)(iTemp23);
			float fThen4 = 0.300000012f * dsp->fRec28[0] + 0.0500000007f;
			float fTemp24 = 0.144717798f * ((iTemp22) ? 0.00100000005f : fThen4);
			int iTemp25 = fabsf(fTemp24) < 1.1920929e-07f;
			float fThen6 = expf(0.0f - dsp->fConst41 / ((iTemp25) ? 1.0f : fTemp24));
			float fTemp26 = ((iTemp25) ? 0.0f : fThen6);
			float fElse7 = (float)(iTemp21);
			dsp->fRec25[0] = (1.0f - fTemp26) * ((iTemp22) ? fElse7 : 0.0f) + fTemp26 * dsp->fRec25[1];
			dsp->fRec29[0] = dsp->fConst57 + dsp->fRec29[1] - floorf(dsp->fConst57 + dsp->fRec29[1]);
			float fTemp27 = dsp->fRec25[0] * fTemp15 * ftbl0mydspSIG0[(int)(4096.0f * dsp->fRec29[0])];
			dsp->fVec8[0] = fTemp27;
			dsp->fRec24[0] = dsp->fConst38 * (dsp->fConst39 * fTemp27 + dsp->fConst51 * dsp->fVec8[1]) - dsp->fConst52 * dsp->fRec24[1];
			dsp->fRec23[0] = dsp->fRec24[0] - dsp->fConst32 * (dsp->fConst53 * dsp->fRec23[2] + dsp->fConst54 * dsp->fRec23[1]);
			dsp->fRec33[0] = dsp->fConst58 + dsp->fRec33[1] - floorf(dsp->fConst58 + dsp->fRec33[1]);
			float fTemp28 = dsp->fRec33[0] - dsp->fRec33[1];
			dsp->fVec9[0] = fTemp28;
			int iTemp29 = (dsp->fVec9[1] <= 0.0f) & (fTemp28 > 0.0f);
			dsp->fRec34[0] = dsp->fRec34[1] * (float)(1 - iTemp29) + 4.65661287e-10f * fTemp0 * (float)(iTemp29);
			float fTemp30 = 0.5f * (dsp->fRec34[0] + 1.0f);
			float fTemp31 = dsp->fVec1[1] * (float)((dsp->fRec33[0] >= fTemp30) * (dsp->fRec33[1] < fTemp30));
			dsp->fVec10[0] = fTemp31;
			int iTemp32 = 4.65661287e-10f * fTemp31 > 0.0f;
			int iTemp33 = iTemp32;
			int iTemp34 = (4.65661287e-10f * dsp->fVec10[1] <= 0.0f) & iTemp32;
			dsp->fRec35[0] = dsp->fRec35[1] * (float)(1 - iTemp34) + fTemp11 * (float)(iTemp34);
			float fThen8 = 0.300000012f * (dsp->fRec35[0] + 1.0f);
			float fTemp35 = 0.144717798f * ((iTemp33) ? 0.00100000005f : fThen8);
			int iTemp36 = fabsf(fTemp35) < 1.1920929e-07f;
			float fThen10 = expf(0.0f - dsp->fConst41 / ((iTemp36) ? 1.0f : fTemp35));
			float fTemp37 = ((iTemp36) ? 0.0f : fThen10);
			float fElse11 = (float)(iTemp32);
			dsp->fRec32[0] = (1.0f - fTemp37) * ((iTemp33) ? fElse11 : 0.0f) + fTemp37 * dsp->fRec32[1];
			dsp->fRec36[0] = dsp->fConst59 + dsp->fRec36[1] - floorf(dsp->fConst59 + dsp->fRec36[1]);
			float fTemp38 = dsp->fRec32[0] * fTemp15 * ftbl0mydspSIG0[(int)(4096.0f * dsp->fRec36[0])];
			dsp->fVec11[0] = fTemp38;
			dsp->fRec31[0] = dsp->fConst38 * (dsp->fConst39 * fTemp38 + dsp->fConst51 * dsp->fVec11[1]) - dsp->fConst52 * dsp->fRec31[1];
			dsp->fRec30[0] = dsp->fRec31[0] - dsp->fConst32 * (dsp->fConst53 * dsp->fRec30[2] + dsp->fConst54 * dsp->fRec30[1]);
			float fTemp39 = dsp->fConst34 * dsp->fRec13[0] + dsp->fConst55 * dsp->fRec13[1] + dsp->fConst34 * dsp->fRec13[2] + 12.0f * (dsp->fConst34 * dsp->fRec23[0] + dsp->fConst55 * dsp->fRec23[1] + dsp->fConst34 * dsp->fRec23[2]) + 20.0f * (dsp->fConst34 * dsp->fRec30[0] + dsp->fConst55 * dsp->fRec30[1] + dsp->fConst34 * dsp->fRec30[2]);
			float fTemp40 = fTemp3 + dsp->fConst32 * fTemp39;
			dsp->fVec12[0] = fTemp40;
			dsp->fRec38[0] = 0.0f - dsp->fConst17 * (dsp->fConst18 * dsp->fRec38[1] - (fTemp40 + dsp->fVec12[1]));
			dsp->fRec37[0] = dsp->fRec38[0] - dsp->fConst32 * (dsp->fConst53 * dsp->fRec37[2] + dsp->fConst54 * dsp->fRec37[1]);
			dsp->fRec40[0] = dsp->fConst60 * dsp->fVec12[1] - dsp->fConst43 * (dsp->fConst44 * dsp->fRec40[1] - dsp->fConst36 * fTemp40);
			dsp->fRec39[0] = dsp->fRec40[0] - dsp->fConst45 * (dsp->fConst46 * dsp->fRec39[2] + dsp->fConst49 * dsp->fRec39[1]);
			output0[i0] = (FAUSTFLOAT)(fTemp3 + dsp->fConst32 * (fTemp39 + dsp->fRec37[2] + dsp->fRec37[0] + 2.0f * dsp->fRec37[1]) + dsp->fConst45 * (dsp->fConst48 * dsp->fRec39[0] + dsp->fConst61 * dsp->fRec39[1] + dsp->fConst48 * dsp->fRec39[2]));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->iRec2[1] = dsp->iRec2[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec0[2] = dsp->fRec0[1];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec8[1] = dsp->fRec8[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec11[2] = dsp->fRec11[1];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec19[2] = dsp->fRec19[1];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec13[2] = dsp->fRec13[1];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fRec28[1] = dsp->fRec28[0];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec29[1] = dsp->fRec29[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fRec23[2] = dsp->fRec23[1];
			dsp->fRec23[1] = dsp->fRec23[0];
			dsp->fRec33[1] = dsp->fRec33[0];
			dsp->fVec9[1] = dsp->fVec9[0];
			dsp->fRec34[1] = dsp->fRec34[0];
			dsp->fVec10[1] = dsp->fVec10[0];
			dsp->fRec35[1] = dsp->fRec35[0];
			dsp->fRec32[1] = dsp->fRec32[0];
			dsp->fRec36[1] = dsp->fRec36[0];
			dsp->fVec11[1] = dsp->fVec11[0];
			dsp->fRec31[1] = dsp->fRec31[0];
			dsp->fRec30[2] = dsp->fRec30[1];
			dsp->fRec30[1] = dsp->fRec30[0];
			dsp->fVec12[1] = dsp->fVec12[0];
			dsp->fRec38[1] = dsp->fRec38[0];
			dsp->fRec37[2] = dsp->fRec37[1];
			dsp->fRec37[1] = dsp->fRec37[0];
			dsp->fRec40[1] = dsp->fRec40[0];
			dsp->fRec39[2] = dsp->fRec39[1];
			dsp->fRec39[1] = dsp->fRec39[0];
		}
	}
}

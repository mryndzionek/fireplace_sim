/* ------------------------------------------------------------
name: "fireplace"
Code generated with Faust 2.41.1 (https://faust.grame.fr)
Compilation options: -lang c -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "faust_dsp.h"

typedef struct
{
	int iVec4[2];
	int iRec23[2];
} mydspSIG0;

static mydspSIG0 *newmydspSIG0() { return (mydspSIG0 *)calloc(1, sizeof(mydspSIG0)); }
static void deletemydspSIG0(mydspSIG0 *dsp) { free(dsp); }

static void classInitmydsp(int sample_rate);
static void initmydsp(mydsp_t *dsp, int sample_rate);

static void instanceInitmydspSIG0(mydspSIG0 *dsp, int sample_rate)
{
	/* C99 loop */
	{
		int l25;
		for (l25 = 0; l25 < 2; l25 = l25 + 1)
		{
			dsp->iVec4[l25] = 0;
		}
	}
	/* C99 loop */
	{
		int l26;
		for (l26 = 0; l26 < 2; l26 = l26 + 1)
		{
			dsp->iRec23[l26] = 0;
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
			dsp->iRec23[0] = (dsp->iVec4[1] + dsp->iRec23[1]) % 4096;
			table[i1] = sinf(0.00153398083f * (float)(dsp->iRec23[0]));
			dsp->iVec4[1] = dsp->iVec4[0];
			dsp->iRec23[1] = dsp->iRec23[0];
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
	bool wet;
	int fSampleRate;
	float fConst4;
	float fConst8;
	float fConst9;
	int iVec0[2];
	float fConst11;
	float fConst12;
	float fRec6[2];
	float fRec7[2];
	int iRec8[2];
	float fVec1[2];
	float fRec5[2];
	float fRec4[2];
	float fRec3[2];
	float fRec2[2];
	float fRec1[2];
	float fRec0[2];
	float fConst14;
	float fConst16;
	float fConst17;
	float fConst18;
	float fRec10[2];
	float fConst19;
	float fConst20;
	float fConst21;
	float fRec9[3];
	float fConst22;
	float fConst25;
	float fConst26;
	float fConst27;
	float fRec12[2];
	float fConst28;
	float fConst29;
	float fRec11[3];
	float fConst30;
	float fConst32;
	float fConst34;
	float fConst36;
	float fConst37;
	float fConst38;
	float fRec17[2];
	float fVec2[2];
	float fRec18[2];
	float fVec3[2];
	float fConst39;
	float fRec19[2];
	float fRec16[2];
	float fRec20[2];
	float fConst40;
	float fRec15[2];
	float fConst42;
	float fConst43;
	float fRec22[2];
	float fConst44;
	float fConst45;
	float fConst47;
	float fConst48;
	float fRec21[3];
	float fConst49;
	float fRec24[2];
	float fVec5[2];
	float fConst50;
	float fConst51;
	float fRec14[2];
	float fConst52;
	float fConst53;
	float fRec13[3];
	float fConst54;
	float fConst55;
	float fRec31[2];
	float fVec6[2];
	float fRec32[2];
	float fVec7[2];
	float fRec33[2];
	float fRec30[2];
	float fRec34[2];
	float fRec29[2];
	float fConst56;
	float fRec35[2];
	float fVec8[2];
	float fRec28[2];
	float fRec27[3];
	float fConst57;
	float fRec40[2];
	float fVec9[2];
	float fRec41[2];
	float fVec10[2];
	float fRec42[2];
	float fRec39[2];
	float fRec43[2];
	float fRec38[2];
	float fConst58;
	float fRec44[2];
	float fVec11[2];
	float fRec37[2];
	float fRec36[3];
	float fVec12[2];
	float fRec26[2];
	float fRec25[3];
	float fConst59;
	float fRec46[2];
	float fRec45[3];
	float fConst60;
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
	dsp->wet = false;
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
			dsp->fRec6[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1)
		{
			dsp->fRec7[l2] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 2; l3 = l3 + 1)
		{
			dsp->iRec8[l3] = 0;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1)
		{
			dsp->fVec1[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 2; l5 = l5 + 1)
		{
			dsp->fRec5[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1)
		{
			dsp->fRec4[l6] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l7;
		for (l7 = 0; l7 < 2; l7 = l7 + 1)
		{
			dsp->fRec3[l7] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l8;
		for (l8 = 0; l8 < 2; l8 = l8 + 1)
		{
			dsp->fRec2[l8] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l9;
		for (l9 = 0; l9 < 2; l9 = l9 + 1)
		{
			dsp->fRec1[l9] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l10;
		for (l10 = 0; l10 < 2; l10 = l10 + 1)
		{
			dsp->fRec0[l10] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l11;
		for (l11 = 0; l11 < 2; l11 = l11 + 1)
		{
			dsp->fRec10[l11] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l12;
		for (l12 = 0; l12 < 3; l12 = l12 + 1)
		{
			dsp->fRec9[l12] = 0.0f;
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
			dsp->fRec17[l15] = 0.0f;
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
			dsp->fRec18[l17] = 0.0f;
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
			dsp->fRec19[l19] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l20;
		for (l20 = 0; l20 < 2; l20 = l20 + 1)
		{
			dsp->fRec16[l20] = 0.0f;
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
		for (l22 = 0; l22 < 2; l22 = l22 + 1)
		{
			dsp->fRec15[l22] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l23;
		for (l23 = 0; l23 < 2; l23 = l23 + 1)
		{
			dsp->fRec22[l23] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l24;
		for (l24 = 0; l24 < 3; l24 = l24 + 1)
		{
			dsp->fRec21[l24] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l27;
		for (l27 = 0; l27 < 2; l27 = l27 + 1)
		{
			dsp->fRec24[l27] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l28;
		for (l28 = 0; l28 < 2; l28 = l28 + 1)
		{
			dsp->fVec5[l28] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l29;
		for (l29 = 0; l29 < 2; l29 = l29 + 1)
		{
			dsp->fRec14[l29] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l30;
		for (l30 = 0; l30 < 3; l30 = l30 + 1)
		{
			dsp->fRec13[l30] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l31;
		for (l31 = 0; l31 < 2; l31 = l31 + 1)
		{
			dsp->fRec31[l31] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l32;
		for (l32 = 0; l32 < 2; l32 = l32 + 1)
		{
			dsp->fVec6[l32] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l33;
		for (l33 = 0; l33 < 2; l33 = l33 + 1)
		{
			dsp->fRec32[l33] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l34;
		for (l34 = 0; l34 < 2; l34 = l34 + 1)
		{
			dsp->fVec7[l34] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l35;
		for (l35 = 0; l35 < 2; l35 = l35 + 1)
		{
			dsp->fRec33[l35] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l36;
		for (l36 = 0; l36 < 2; l36 = l36 + 1)
		{
			dsp->fRec30[l36] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l37;
		for (l37 = 0; l37 < 2; l37 = l37 + 1)
		{
			dsp->fRec34[l37] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l38;
		for (l38 = 0; l38 < 2; l38 = l38 + 1)
		{
			dsp->fRec29[l38] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l39;
		for (l39 = 0; l39 < 2; l39 = l39 + 1)
		{
			dsp->fRec35[l39] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l40;
		for (l40 = 0; l40 < 2; l40 = l40 + 1)
		{
			dsp->fVec8[l40] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l41;
		for (l41 = 0; l41 < 2; l41 = l41 + 1)
		{
			dsp->fRec28[l41] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l42;
		for (l42 = 0; l42 < 3; l42 = l42 + 1)
		{
			dsp->fRec27[l42] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l43;
		for (l43 = 0; l43 < 2; l43 = l43 + 1)
		{
			dsp->fRec40[l43] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l44;
		for (l44 = 0; l44 < 2; l44 = l44 + 1)
		{
			dsp->fVec9[l44] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l45;
		for (l45 = 0; l45 < 2; l45 = l45 + 1)
		{
			dsp->fRec41[l45] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l46;
		for (l46 = 0; l46 < 2; l46 = l46 + 1)
		{
			dsp->fVec10[l46] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l47;
		for (l47 = 0; l47 < 2; l47 = l47 + 1)
		{
			dsp->fRec42[l47] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l48;
		for (l48 = 0; l48 < 2; l48 = l48 + 1)
		{
			dsp->fRec39[l48] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l49;
		for (l49 = 0; l49 < 2; l49 = l49 + 1)
		{
			dsp->fRec43[l49] = 0.0f;
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
		for (l51 = 0; l51 < 2; l51 = l51 + 1)
		{
			dsp->fRec44[l51] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l52;
		for (l52 = 0; l52 < 2; l52 = l52 + 1)
		{
			dsp->fVec11[l52] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l53;
		for (l53 = 0; l53 < 2; l53 = l53 + 1)
		{
			dsp->fRec37[l53] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l54;
		for (l54 = 0; l54 < 3; l54 = l54 + 1)
		{
			dsp->fRec36[l54] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l55;
		for (l55 = 0; l55 < 2; l55 = l55 + 1)
		{
			dsp->fVec12[l55] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l56;
		for (l56 = 0; l56 < 2; l56 = l56 + 1)
		{
			dsp->fRec26[l56] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l57;
		for (l57 = 0; l57 < 3; l57 = l57 + 1)
		{
			dsp->fRec25[l57] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l58;
		for (l58 = 0; l58 < 2; l58 = l58 + 1)
		{
			dsp->fRec46[l58] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l59;
		for (l59 = 0; l59 < 3; l59 = l59 + 1)
		{
			dsp->fRec45[l59] = 0.0f;
		}
	}
}

static void instanceConstantsmydsp(mydsp_t *dsp, int sample_rate)
{
	dsp->fSampleRate = sample_rate;
	float fConst0 = fminf(192000.0f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	float fConst1 = tanf(9424.77832f / fConst0);
	float fConst2 = 1.0f / fConst1;
	float fConst3 = (fConst2 + 1.0f) / fConst1 + 1.0f;
	dsp->fConst4 = 0.100000001f / fConst3;
	float fConst5 = tanf(3141.59277f / fConst0);
	float fConst6 = 1.0f / fConst5;
	float fConst7 = fConst6 + 1.0f;
	dsp->fConst8 = 1.0f / fConst7;
	dsp->fConst9 = 1.0f - fConst6;
	float fConst10 = 6283.18555f / fConst0;
	dsp->fConst11 = sinf(fConst10);
	dsp->fConst12 = cosf(fConst10);
	float fConst13 = mydsp_faustpower2_f(fConst1);
	dsp->fConst14 = 1.0f / fConst13;
	float fConst15 = fConst2 + 1.0f;
	dsp->fConst16 = 1.0f / (fConst1 * fConst15);
	dsp->fConst17 = 0.0f - dsp->fConst16;
	dsp->fConst18 = (1.0f - fConst2) / fConst15;
	dsp->fConst19 = 1.0f / fConst3;
	dsp->fConst20 = (fConst2 + -1.0f) / fConst1 + 1.0f;
	dsp->fConst21 = 2.0f * (1.0f - dsp->fConst14);
	dsp->fConst22 = 0.0f - 2.0f / fConst13;
	float fConst23 = tanf(1570.79639f / fConst0);
	float fConst24 = 1.0f / fConst23;
	dsp->fConst25 = 1.0f / ((fConst24 + 1.0f) / fConst23 + 1.0f);
	dsp->fConst26 = 1.0f / (fConst24 + 1.0f);
	dsp->fConst27 = 1.0f - fConst24;
	dsp->fConst28 = (fConst24 + -1.0f) / fConst23 + 1.0f;
	dsp->fConst29 = 2.0f * (1.0f - 1.0f / mydsp_faustpower2_f(fConst23));
	dsp->fConst30 = 1.0f / ((fConst6 + 1.0f) / fConst5 + 1.0f);
	float fConst31 = mydsp_faustpower2_f(fConst5);
	dsp->fConst32 = 1.0f / fConst31;
	float fConst33 = tanf(31415.9258f / fConst0);
	dsp->fConst34 = 1.0f / fConst33;
	float fConst35 = (dsp->fConst34 + 1.0f) / fConst33 + 1.0f;
	dsp->fConst36 = 0.769999981f / fConst35;
	dsp->fConst37 = 1.0f / (fConst5 * fConst7);
	dsp->fConst38 = 5.0f / fConst0;
	dsp->fConst39 = 0.00100000005f * fConst0;
	dsp->fConst40 = 1.0f / fConst0;
	float fConst41 = dsp->fConst34 + 1.0f;
	dsp->fConst42 = 1.0f / fConst41;
	dsp->fConst43 = 1.0f - dsp->fConst34;
	dsp->fConst44 = 1.0f / fConst35;
	dsp->fConst45 = (dsp->fConst34 + -1.0f) / fConst33 + 1.0f;
	float fConst46 = mydsp_faustpower2_f(fConst33);
	dsp->fConst47 = 1.0f / fConst46;
	dsp->fConst48 = 2.0f * (1.0f - dsp->fConst47);
	dsp->fConst49 = 10.0f / fConst0;
	dsp->fConst50 = 0.0f - dsp->fConst37;
	dsp->fConst51 = dsp->fConst9 / fConst7;
	dsp->fConst52 = (fConst6 + -1.0f) / fConst5 + 1.0f;
	dsp->fConst53 = 2.0f * (1.0f - dsp->fConst32);
	dsp->fConst54 = 0.0f - 2.0f / fConst31;
	dsp->fConst55 = 0.100000001f / fConst0;
	dsp->fConst56 = 500.0f / fConst0;
	dsp->fConst57 = 0.200000003f / fConst0;
	dsp->fConst58 = 250.0f / fConst0;
	dsp->fConst59 = 0.0f - 1.0f / (fConst33 * fConst41);
	dsp->fConst60 = 0.0f - 2.0f / fConst46;
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
	float fSlow0 = (float)(dsp->wet);
	float fSlow1 = dsp->fConst30 * fSlow0;
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1)
		{
			dsp->iVec0[0] = 1;
			dsp->fRec6[0] = dsp->fConst11 * dsp->fRec7[1] + dsp->fConst12 * dsp->fRec6[1];
			dsp->fRec7[0] = ((float)(1 - dsp->iVec0[1]) + dsp->fConst12 * dsp->fRec7[1]) - dsp->fConst11 * dsp->fRec6[1];
			int iTemp0 = (dsp->fRec6[1] <= 0.0f) & (dsp->fRec6[0] > 0.0f);
			dsp->iRec8[0] = 1103515245 * dsp->iRec8[1] + 12345;
			float fTemp1 = (float)(dsp->iRec8[0]);
			dsp->fVec1[0] = fTemp1;
			dsp->fRec5[0] = dsp->fRec5[1] * (float)(1 - iTemp0) + 4.65661287e-10f * fTemp1 * (float)(iTemp0);
			dsp->fRec4[0] = 0.0f - dsp->fConst8 * (dsp->fConst9 * dsp->fRec4[1] - (dsp->fRec5[0] + dsp->fRec5[1]));
			dsp->fRec3[0] = 0.0f - dsp->fConst8 * (dsp->fConst9 * dsp->fRec3[1] - (dsp->fRec4[0] + dsp->fRec4[1]));
			dsp->fRec2[0] = 0.0f - dsp->fConst8 * (dsp->fConst9 * dsp->fRec2[1] - (dsp->fRec3[0] + dsp->fRec3[1]));
			dsp->fRec1[0] = 0.0f - dsp->fConst8 * (dsp->fConst9 * dsp->fRec1[1] - (dsp->fRec2[0] + dsp->fRec2[1]));
			dsp->fRec0[0] = 0.0f - dsp->fConst8 * (dsp->fConst9 * dsp->fRec0[1] - (dsp->fRec1[0] + dsp->fRec1[1]));
			dsp->fRec10[0] = 4.65661287e-10f * (dsp->fConst16 * fTemp1 + dsp->fConst17 * dsp->fVec1[1]) - dsp->fConst18 * dsp->fRec10[1];
			dsp->fRec9[0] = dsp->fRec10[0] - dsp->fConst19 * (dsp->fConst20 * dsp->fRec9[2] + dsp->fConst21 * dsp->fRec9[1]);
			float fTemp2 = 4.65661287e-10f * (fTemp1 + dsp->fVec1[1]);
			dsp->fRec12[0] = dsp->fConst26 * (fTemp2 - dsp->fConst27 * dsp->fRec12[1]);
			dsp->fRec11[0] = dsp->fRec12[0] - dsp->fConst25 * (dsp->fConst28 * dsp->fRec11[2] + dsp->fConst29 * dsp->fRec11[1]);
			dsp->fRec17[0] = dsp->fConst38 + dsp->fRec17[1] - floorf(dsp->fConst38 + dsp->fRec17[1]);
			float fTemp3 = dsp->fRec17[0] - dsp->fRec17[1];
			dsp->fVec2[0] = fTemp3;
			int iTemp4 = (dsp->fVec2[1] <= 0.0f) & (fTemp3 > 0.0f);
			dsp->fRec18[0] = dsp->fRec18[1] * (float)(1 - iTemp4) + 4.65661287e-10f * fTemp1 * (float)(iTemp4);
			float fTemp5 = 0.5f * (dsp->fRec18[0] + 1.0f);
			float fTemp6 = fabsf(4.65661287e-10f * dsp->fVec1[1] * (float)((dsp->fRec17[0] >= fTemp5) * (dsp->fRec17[1] < fTemp5)));
			dsp->fVec3[0] = fTemp6;
			int iTemp7 = fTemp6 > 0.0f;
			int iTemp8 = (dsp->fVec3[1] <= 0.0f) & iTemp7;
			float fTemp9 = (float)(1 - iTemp8);
			float fTemp10 = (float)(iTemp8);
			dsp->fRec19[0] = dsp->fRec19[1] * fTemp9 + fTemp6 * fTemp10;
			float fThen0 = fmaxf(0.0f, dsp->fRec16[1] + -1.0f);
			float fElse0 = dsp->fConst39 * (8.0f * dsp->fRec19[0] + 2.0f);
			dsp->fRec16[0] = ((iTemp7 > 0) ? fElse0 : fThen0);
			int iTemp11 = (dsp->fRec16[0] > 0.0f) > 0;
			int iTemp12 = iTemp11;
			float fTemp13 = fabsf(4.65661287e-10f * fTemp1);
			dsp->fRec20[0] = fTemp9 * dsp->fRec20[1] + fTemp10 * fTemp13;
			float fThen1 = 0.300000012f * dsp->fRec20[0] + 0.100000001f;
			float fTemp14 = 0.144717798f * ((iTemp12) ? 0.00100000005f : fThen1);
			int iTemp15 = fabsf(fTemp14) < 1.1920929e-07f;
			float fThen3 = expf(0.0f - dsp->fConst40 / ((iTemp15) ? 1.0f : fTemp14));
			float fTemp16 = ((iTemp15) ? 0.0f : fThen3);
			float fElse4 = (float)(iTemp11);
			dsp->fRec15[0] = (1.0f - fTemp16) * ((iTemp12) ? fElse4 : 0.0f) + fTemp16 * dsp->fRec15[1];
			dsp->fRec22[0] = dsp->fConst42 * (fTemp2 - dsp->fConst43 * dsp->fRec22[1]);
			dsp->fRec21[0] = dsp->fRec22[0] - dsp->fConst44 * (dsp->fConst45 * dsp->fRec21[2] + dsp->fConst48 * dsp->fRec21[1]);
			float fTemp17 = dsp->fRec21[2] + dsp->fRec21[0] + 2.0f * dsp->fRec21[1];
			dsp->fRec24[0] = dsp->fConst49 + dsp->fRec24[1] - floorf(dsp->fConst49 + dsp->fRec24[1]);
			float fTemp18 = dsp->fRec15[0] * fTemp17 * ftbl0mydspSIG0[(int)(4096.0f * dsp->fRec24[0])];
			dsp->fVec5[0] = fTemp18;
			dsp->fRec14[0] = dsp->fConst36 * (dsp->fConst37 * fTemp18 + dsp->fConst50 * dsp->fVec5[1]) - dsp->fConst51 * dsp->fRec14[1];
			dsp->fRec13[0] = dsp->fRec14[0] - dsp->fConst30 * (dsp->fConst52 * dsp->fRec13[2] + dsp->fConst53 * dsp->fRec13[1]);
			float fTemp19 = dsp->fConst4 * mydsp_faustpower2_f(dsp->fRec0[0]) * (dsp->fConst14 * dsp->fRec9[0] + dsp->fConst22 * dsp->fRec9[1] + dsp->fConst14 * dsp->fRec9[2]) + 0.200000003f * (dsp->fConst25 * (dsp->fRec11[2] + dsp->fRec11[0] + 2.0f * dsp->fRec11[1]) + dsp->fConst30 * (dsp->fConst32 * dsp->fRec13[0] + dsp->fConst54 * dsp->fRec13[1] + dsp->fConst32 * dsp->fRec13[2]));
			dsp->fRec31[0] = dsp->fConst55 + dsp->fRec31[1] - floorf(dsp->fConst55 + dsp->fRec31[1]);
			float fTemp20 = dsp->fRec31[0] - dsp->fRec31[1];
			dsp->fVec6[0] = fTemp20;
			int iTemp21 = (dsp->fVec6[1] <= 0.0f) & (fTemp20 > 0.0f);
			dsp->fRec32[0] = dsp->fRec32[1] * (float)(1 - iTemp21) + 4.65661287e-10f * fTemp1 * (float)(iTemp21);
			float fTemp22 = 0.5f * (dsp->fRec32[0] + 1.0f);
			float fTemp23 = fabsf(4.65661287e-10f * dsp->fVec1[1] * (float)((dsp->fRec31[0] >= fTemp22) * (dsp->fRec31[1] < fTemp22)));
			dsp->fVec7[0] = fTemp23;
			int iTemp24 = fTemp23 > 0.0f;
			int iTemp25 = (dsp->fVec7[1] <= 0.0f) & iTemp24;
			float fTemp26 = (float)(1 - iTemp25);
			float fTemp27 = (float)(iTemp25);
			dsp->fRec33[0] = dsp->fRec33[1] * fTemp26 + fTemp23 * fTemp27;
			float fThen5 = fmaxf(0.0f, dsp->fRec30[1] + -1.0f);
			float fElse5 = dsp->fConst39 * (8.0f * dsp->fRec33[0] + 2.0f);
			dsp->fRec30[0] = ((iTemp24 > 0) ? fElse5 : fThen5);
			int iTemp28 = (dsp->fRec30[0] > 0.0f) > 0;
			int iTemp29 = iTemp28;
			dsp->fRec34[0] = fTemp26 * dsp->fRec34[1] + fTemp13 * fTemp27;
			float fThen6 = 0.300000012f * dsp->fRec34[0] + 0.0500000007f;
			float fTemp30 = 0.144717798f * ((iTemp29) ? 0.00100000005f : fThen6);
			int iTemp31 = fabsf(fTemp30) < 1.1920929e-07f;
			float fThen8 = expf(0.0f - dsp->fConst40 / ((iTemp31) ? 1.0f : fTemp30));
			float fTemp32 = ((iTemp31) ? 0.0f : fThen8);
			float fElse9 = (float)(iTemp28);
			dsp->fRec29[0] = (1.0f - fTemp32) * ((iTemp29) ? fElse9 : 0.0f) + fTemp32 * dsp->fRec29[1];
			dsp->fRec35[0] = dsp->fConst56 + dsp->fRec35[1] - floorf(dsp->fConst56 + dsp->fRec35[1]);
			float fTemp33 = dsp->fRec29[0] * fTemp17 * ftbl0mydspSIG0[(int)(4096.0f * dsp->fRec35[0])];
			dsp->fVec8[0] = fTemp33;
			dsp->fRec28[0] = dsp->fConst36 * (dsp->fConst37 * fTemp33 + dsp->fConst50 * dsp->fVec8[1]) - dsp->fConst51 * dsp->fRec28[1];
			dsp->fRec27[0] = dsp->fRec28[0] - dsp->fConst30 * (dsp->fConst52 * dsp->fRec27[2] + dsp->fConst53 * dsp->fRec27[1]);
			dsp->fRec40[0] = dsp->fConst57 + dsp->fRec40[1] - floorf(dsp->fConst57 + dsp->fRec40[1]);
			float fTemp34 = dsp->fRec40[0] - dsp->fRec40[1];
			dsp->fVec9[0] = fTemp34;
			int iTemp35 = (dsp->fVec9[1] <= 0.0f) & (fTemp34 > 0.0f);
			dsp->fRec41[0] = dsp->fRec41[1] * (float)(1 - iTemp35) + 4.65661287e-10f * fTemp1 * (float)(iTemp35);
			float fTemp36 = 0.5f * (dsp->fRec41[0] + 1.0f);
			float fTemp37 = fabsf(4.65661287e-10f * dsp->fVec1[1] * (float)((dsp->fRec40[0] >= fTemp36) * (dsp->fRec40[1] < fTemp36)));
			dsp->fVec10[0] = fTemp37;
			int iTemp38 = fTemp37 > 0.0f;
			int iTemp39 = (dsp->fVec10[1] <= 0.0f) & iTemp38;
			float fTemp40 = (float)(1 - iTemp39);
			float fTemp41 = (float)(iTemp39);
			dsp->fRec42[0] = dsp->fRec42[1] * fTemp40 + fTemp37 * fTemp41;
			float fThen10 = fmaxf(0.0f, dsp->fRec39[1] + -1.0f);
			float fElse10 = dsp->fConst39 * (8.0f * dsp->fRec42[0] + 2.0f);
			dsp->fRec39[0] = ((iTemp38 > 0) ? fElse10 : fThen10);
			int iTemp42 = (dsp->fRec39[0] > 0.0f) > 0;
			int iTemp43 = iTemp42;
			dsp->fRec43[0] = fTemp40 * dsp->fRec43[1] + fTemp13 * fTemp41;
			float fThen11 = 0.300000012f * (dsp->fRec43[0] + 1.0f);
			float fTemp44 = 0.144717798f * ((iTemp43) ? 0.00100000005f : fThen11);
			int iTemp45 = fabsf(fTemp44) < 1.1920929e-07f;
			float fThen13 = expf(0.0f - dsp->fConst40 / ((iTemp45) ? 1.0f : fTemp44));
			float fTemp46 = ((iTemp45) ? 0.0f : fThen13);
			float fElse14 = (float)(iTemp42);
			dsp->fRec38[0] = (1.0f - fTemp46) * ((iTemp43) ? fElse14 : 0.0f) + fTemp46 * dsp->fRec38[1];
			dsp->fRec44[0] = dsp->fConst58 + dsp->fRec44[1] - floorf(dsp->fConst58 + dsp->fRec44[1]);
			float fTemp47 = dsp->fRec38[0] * fTemp17 * ftbl0mydspSIG0[(int)(4096.0f * dsp->fRec44[0])];
			dsp->fVec11[0] = fTemp47;
			dsp->fRec37[0] = dsp->fConst36 * (dsp->fConst37 * fTemp47 + dsp->fConst50 * dsp->fVec11[1]) - dsp->fConst51 * dsp->fRec37[1];
			dsp->fRec36[0] = dsp->fRec37[0] - dsp->fConst30 * (dsp->fConst52 * dsp->fRec36[2] + dsp->fConst53 * dsp->fRec36[1]);
			float fTemp48 = 3.0f * (dsp->fConst32 * dsp->fRec27[0] + dsp->fConst54 * dsp->fRec27[1] + dsp->fConst32 * dsp->fRec27[2]) + 2.0f * (dsp->fConst32 * dsp->fRec36[0] + dsp->fConst54 * dsp->fRec36[1] + dsp->fConst32 * dsp->fRec36[2]);
			float fTemp49 = fTemp19 + fSlow1 * fTemp48;
			dsp->fVec12[0] = fTemp49;
			dsp->fRec26[0] = 0.0f - dsp->fConst8 * (dsp->fConst9 * dsp->fRec26[1] - (fTemp49 + dsp->fVec12[1]));
			dsp->fRec25[0] = dsp->fRec26[0] - dsp->fConst30 * (dsp->fConst52 * dsp->fRec25[2] + dsp->fConst53 * dsp->fRec25[1]);
			dsp->fRec46[0] = dsp->fConst59 * dsp->fVec12[1] - dsp->fConst42 * (dsp->fConst43 * dsp->fRec46[1] - dsp->fConst34 * fTemp49);
			dsp->fRec45[0] = dsp->fRec46[0] - dsp->fConst44 * (dsp->fConst45 * dsp->fRec45[2] + dsp->fConst48 * dsp->fRec45[1]);
			output0[i0] = (FAUSTFLOAT)(fTemp19 + dsp->fConst30 * (dsp->fRec25[2] + dsp->fRec25[0] + 2.0f * dsp->fRec25[1] + fSlow0 * fTemp48) + dsp->fConst44 * (dsp->fConst47 * dsp->fRec45[0] + dsp->fConst60 * dsp->fRec45[1] + dsp->fConst47 * dsp->fRec45[2]));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec6[1] = dsp->fRec6[0];
			dsp->fRec7[1] = dsp->fRec7[0];
			dsp->iRec8[1] = dsp->iRec8[0];
			dsp->fVec1[1] = dsp->fVec1[0];
			dsp->fRec5[1] = dsp->fRec5[0];
			dsp->fRec4[1] = dsp->fRec4[0];
			dsp->fRec3[1] = dsp->fRec3[0];
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec10[1] = dsp->fRec10[0];
			dsp->fRec9[2] = dsp->fRec9[1];
			dsp->fRec9[1] = dsp->fRec9[0];
			dsp->fRec12[1] = dsp->fRec12[0];
			dsp->fRec11[2] = dsp->fRec11[1];
			dsp->fRec11[1] = dsp->fRec11[0];
			dsp->fRec17[1] = dsp->fRec17[0];
			dsp->fVec2[1] = dsp->fVec2[0];
			dsp->fRec18[1] = dsp->fRec18[0];
			dsp->fVec3[1] = dsp->fVec3[0];
			dsp->fRec19[1] = dsp->fRec19[0];
			dsp->fRec16[1] = dsp->fRec16[0];
			dsp->fRec20[1] = dsp->fRec20[0];
			dsp->fRec15[1] = dsp->fRec15[0];
			dsp->fRec22[1] = dsp->fRec22[0];
			dsp->fRec21[2] = dsp->fRec21[1];
			dsp->fRec21[1] = dsp->fRec21[0];
			dsp->fRec24[1] = dsp->fRec24[0];
			dsp->fVec5[1] = dsp->fVec5[0];
			dsp->fRec14[1] = dsp->fRec14[0];
			dsp->fRec13[2] = dsp->fRec13[1];
			dsp->fRec13[1] = dsp->fRec13[0];
			dsp->fRec31[1] = dsp->fRec31[0];
			dsp->fVec6[1] = dsp->fVec6[0];
			dsp->fRec32[1] = dsp->fRec32[0];
			dsp->fVec7[1] = dsp->fVec7[0];
			dsp->fRec33[1] = dsp->fRec33[0];
			dsp->fRec30[1] = dsp->fRec30[0];
			dsp->fRec34[1] = dsp->fRec34[0];
			dsp->fRec29[1] = dsp->fRec29[0];
			dsp->fRec35[1] = dsp->fRec35[0];
			dsp->fVec8[1] = dsp->fVec8[0];
			dsp->fRec28[1] = dsp->fRec28[0];
			dsp->fRec27[2] = dsp->fRec27[1];
			dsp->fRec27[1] = dsp->fRec27[0];
			dsp->fRec40[1] = dsp->fRec40[0];
			dsp->fVec9[1] = dsp->fVec9[0];
			dsp->fRec41[1] = dsp->fRec41[0];
			dsp->fVec10[1] = dsp->fVec10[0];
			dsp->fRec42[1] = dsp->fRec42[0];
			dsp->fRec39[1] = dsp->fRec39[0];
			dsp->fRec43[1] = dsp->fRec43[0];
			dsp->fRec38[1] = dsp->fRec38[0];
			dsp->fRec44[1] = dsp->fRec44[0];
			dsp->fVec11[1] = dsp->fVec11[0];
			dsp->fRec37[1] = dsp->fRec37[0];
			dsp->fRec36[2] = dsp->fRec36[1];
			dsp->fRec36[1] = dsp->fRec36[0];
			dsp->fVec12[1] = dsp->fVec12[0];
			dsp->fRec26[1] = dsp->fRec26[0];
			dsp->fRec25[2] = dsp->fRec25[1];
			dsp->fRec25[1] = dsp->fRec25[0];
			dsp->fRec46[1] = dsp->fRec46[0];
			dsp->fRec45[2] = dsp->fRec45[1];
			dsp->fRec45[1] = dsp->fRec45[0];
		}
	}
}

void wet(mydsp_t *dsp, bool wet)
{
	dsp->wet = wet;
}
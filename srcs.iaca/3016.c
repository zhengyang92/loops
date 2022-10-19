#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __uint32_t uint32_t;

int
fn (float *excitationf, int i, int32_t excitation[320],
    const uint8_t ff_silk_quant_offset[2][2], int shellblocks,
    int qoffset_high, uint32_t seed, int voiced)
{
  for (i = 0; i < shellblocks << 4; i++)
    {
      int value = excitation[i];
      excitation[i] =
	value * 256 | ff_silk_quant_offset[voiced][qoffset_high];
      if (value < 0)
	excitation[i] += 20;
      else if (value > 0)
	excitation[i] -= 20;
      seed = 196314165 * seed + 907633515;
      if (seed & 0x80000000)
	excitation[i] *= -1;
      seed += value;
      excitationf[i] = excitation[i] / 8388608.0f;
    }
}

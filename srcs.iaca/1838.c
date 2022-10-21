#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t ** subband_samples_lo, int i, int j,
    int32_t ** subband_samples_hi, float (*input))
{
  for (i = 0; i < 32; i++)
     { IACA_START
      if ((i - 1) & 2)
	input[i] = -subband_samples_lo[i][j] - subband_samples_hi[i][j];
      else
	input[i] = subband_samples_lo[i][j] + subband_samples_hi[i][j];
     } IACA_END
}

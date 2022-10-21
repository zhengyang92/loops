#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * lpc_filter, int i, int a_plus, int a, int32_t * coeffs)
{
  for (i = 1; i <= a_plus / 2; i++)
     { IACA_START
      int coeff_1, coeff_2, tmp;
      coeff_1 = coeffs[i];
      coeff_2 = coeffs[a_plus - i];
      tmp =
	((((coeff_1) << 15) + (lpc_filter[a]) * (coeff_2)) + 0x4000) >> 15;
      coeffs[i] = av_clip_int16_c (tmp);
      tmp =
	((((coeff_2) << 15) + (lpc_filter[a]) * (coeff_1)) + 0x4000) >> 15;
      coeffs[a_plus - i] = av_clip_int16_c (tmp);
} IACA_END }

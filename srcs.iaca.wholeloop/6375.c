#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * coeffs, int add, int i, const int8_t transform[32][32])
{
  int shift = 7;
  IACA_START for (i = 0; i < 4; i++)
    {
      do
	{
	  const int e0 =
	    transform[8 * 0][0] * coeffs[0 * 1] +
	    transform[8 * 2][0] * coeffs[2 * 1];
	  const int e1 =
	    transform[8 * 0][1] * coeffs[0 * 1] +
	    transform[8 * 2][1] * coeffs[2 * 1];
	  const int o0 =
	    transform[8 * 1][0] * coeffs[1 * 1] +
	    transform[8 * 3][0] * coeffs[3 * 1];
	  const int o1 =
	    transform[8 * 1][1] * coeffs[1 * 1] +
	    transform[8 * 3][1] * coeffs[3 * 1];
	  (coeffs[0 * 1]) = av_clip_int16_c (((e0 + o0) + add) >> shift);
	  (coeffs[1 * 1]) = av_clip_int16_c (((e1 + o1) + add) >> shift);
	  (coeffs[2 * 1]) = av_clip_int16_c (((e1 - o1) + add) >> shift);
	  (coeffs[3 * 1]) = av_clip_int16_c (((e0 - o0) + add) >> shift);
	}
      while (0);
      coeffs += 4;
     } IACA_END
}

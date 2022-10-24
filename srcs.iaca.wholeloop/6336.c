#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * coeffs, int i, int add)
{
  int shift = 7;
  IACA_START for (i = 0; i < 4; i++)
    {
      do
	{
	  int c0 = coeffs[0 * 1] + coeffs[2 * 1];
	  int c1 = coeffs[2 * 1] + coeffs[3 * 1];
	  int c2 = coeffs[0 * 1] - coeffs[3 * 1];
	  int c3 = 74 * coeffs[1 * 1];
	  (coeffs[2 * 1]) =
	    av_clip_int16_c (((74 *
			       (coeffs[0 * 1] - coeffs[2 * 1] +
				coeffs[3 * 1])) + add) >> shift);
	  (coeffs[0 * 1]) =
	    av_clip_int16_c (((29 * c0 + 55 * c1 + c3) + add) >> shift);
	  (coeffs[1 * 1]) =
	    av_clip_int16_c (((55 * c2 - 29 * c1 + c3) + add) >> shift);
	  (coeffs[3 * 1]) =
	    av_clip_int16_c (((55 * c0 + 29 * c2 - c3) + add) >> shift);
	}
      while (0);
      coeffs += 4;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * b2, int16_t * b5, int16_t * b1, int16_t * dst, int i,
    int16_t * b4, int width, int16_t * b6, int16_t * b3, int16_t * b7,
    int16_t * b0)
{
  IACA_START for (i = 0; i < width; i++)
    {
      dst[i] =
	((unsigned) dst[i] -
	 ((int)
	  (-8 * (b0[i] + (unsigned) b7[i]) + 21 * (b1[i] + (unsigned) b6[i]) -
	   46 * (b2[i] + (unsigned) b5[i]) + 161 * (b3[i] +
						    (unsigned) b4[i]) +
	   128) >> 8));
}IACA_END}

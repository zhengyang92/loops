#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int hasAlpha, int yalpha, int i, int yalpha1, const int16_t * buf1,
    const int16_t * buf0, const int16_t * abuf1, int dstW,
    const int16_t * abuf0, uint8_t * dest)
{
  for (i = 0; i < dstW; i++)
     { IACA_START
      int Y = (buf0[i] * yalpha1 + buf1[i] * yalpha) >> 19;
      int A;
      Y = av_clip_uint8_c (Y);
      if (hasAlpha)
	{
	  A = (abuf0[i] * yalpha1 + abuf1[i] * yalpha) >> 19;
	  A = av_clip_uint8_c (A);
	}
      dest[i * 2] = Y;
      dest[i * 2 + 1] = hasAlpha ? A : 255;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int hasAlpha, int i, const int16_t * buf0, int dstW,
    const int16_t * abuf0, uint8_t * dest)
{
  IACA_START for (i = 0; i < dstW; i++)
    {
      int Y = (buf0[i] + 64) >> 7;
      int A;
      Y = av_clip_uint8_c (Y);
      if (hasAlpha)
	{
	  A = (abuf0[i] + 64) >> 7;
	  if (A & 0x100)
	    A = av_clip_uint8_c (A);
	}
      dest[i * 2] = Y;
      dest[i * 2 + 1] = hasAlpha ? A : 255;
     } IACA_END
}

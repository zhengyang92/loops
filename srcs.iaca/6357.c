#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int offset, int x, int width, int16_t * src, int wx, int ox,
    uint8_t * dst, int log2Wd)
{
  for (x = 0; x < width; x++)
     { IACA_START
      if (log2Wd >= 1)
	{
	  dst[x] = av_clip_uint8_c (((src[x] * wx + offset) >> log2Wd) + ox);
	}
      else
	{
	  dst[x] = av_clip_uint8_c (src[x] * wx + ox);
	}
     } IACA_END
}

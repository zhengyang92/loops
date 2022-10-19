#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int16_t int16_t;

int
fn (int offset, int width, int x, int wx, int16_t * src, int ox,
    uint16_t * dst, int log2Wd)
{
  for (x = 0; x < width; x++)
    {
      if (log2Wd >= 1)
	{
	  dst[x] =
	    av_clip_uintp2_c (((src[x] * wx + offset) >> log2Wd) + ox, 9);
	}
      else
	{
	  dst[x] = av_clip_uintp2_c (src[x] * wx + ox, 9);
	}
    }
}

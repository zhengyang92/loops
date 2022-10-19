#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int offset, int x, int width, int wx, int16_t * src, int ox,
    uint8_t * dst, int log2Wd)
{
  for (x = 0; x < width; x++)
    {
      if (log2Wd >= 1)
	{
	  dst[x] = av_clip_uint8_c (((src[x] * wx + offset) >> log2Wd) + ox);
	}
      else
	{
	  dst[x] = av_clip_uint8_c (src[x] * wx + ox);
	}
    }
}

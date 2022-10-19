#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t * src, int width, int16_t * dst)
{
  for (int j = 0; j < width; j++)
    {
      int alpha = src[j];
      if (alpha > 0 && alpha < 4080)
	{
	  alpha *= 223;
	  alpha += 128;
	  alpha >>= 8;
	  alpha += 256;
	}
      dst[j] = av_clip_uintp2_c (alpha, 12);
    }
}

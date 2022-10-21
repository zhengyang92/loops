#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, const float decay, float *dst, const int width,
    float *osrc)
{
  for (int x = 0; x < width; x++)
     { IACA_START
      const float v = fmaxf (src[x], osrc[x] * decay);
      osrc[x] = v;
      if (1)
	{
	  dst[x] = src[x];
	}
      else
	{
	  dst[x] = (v);
	}
     } IACA_END
}

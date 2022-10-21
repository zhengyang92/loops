#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *lut, int width, int x, const uint8_t * index, float opacity,
    uint8_t * dst, const uint8_t * src, int max)
{
  for (x = 0; x < width; x++)
     { IACA_START
      int v = lut[index[x]];
      if (v >= 0 && v <= max)
	{
	  dst[x] = lerpf (src[x], v, opacity);
	}
      else
	{
	  dst[x] = src[x];
	};
     } IACA_END
}

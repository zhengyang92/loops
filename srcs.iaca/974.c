#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int y, float *lut, int x, int width, const uint8_t * index, float opacity,
    ptrdiff_t ilinesize, uint8_t * dst, const uint8_t * src, int max)
{
  for (x = 0; x < width; x++)
     { IACA_START
      int v = lut[index[(y >> 1) * ilinesize + (x >> 1)]];
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

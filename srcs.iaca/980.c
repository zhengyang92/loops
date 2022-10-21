#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int y, float *lut, int x, int width, float opacity,
    const uint16_t * index, ptrdiff_t ilinesize, int max, uint16_t * dst,
    const uint16_t * src)
{
  for (x = 0; x < width; x++)
     { IACA_START
      int v = lut[index[(y << 1) * ilinesize + (x << 1)]];
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

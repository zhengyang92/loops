#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (float *lut, int y, int x, int width, float opacity,
    const uint16_t * index, ptrdiff_t ilinesize, int max, uint16_t * dst,
    const uint16_t * src)
{
  for (x = 0; x < width; x++)
    {
      int v = lut[index[(y >> 1) * ilinesize + (x >> 1)]];
      if (v >= 0 && v <= max)
	{
	  dst[x] = lerpf (src[x], v, opacity);
	}
      else
	{
	  dst[x] = src[x];
	};
    }
}

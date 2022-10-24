#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int max, float *lut, int y, int width, int x, const uint8_t * index,
    float opacity, ptrdiff_t ilinesize, const uint8_t * src, uint8_t * dst)
{
  IACA_START for (x = 0; x < width; x++)
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
     } IACA_END
}

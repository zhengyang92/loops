#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float *lut, int width, int x, float opacity, const uint16_t * index,
    int max, uint16_t * dst, const uint16_t * src)
{
  IACA_START for (x = 0; x < width; x++)
    {
      int v = lut[index[x >> 1]];
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

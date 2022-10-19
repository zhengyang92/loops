#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float *lut, int x, int width, const uint8_t * index, float opacity,
    uint8_t * dst, const uint8_t * src, int max)
{
  for (x = 0; x < width; x++)
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
    }
}

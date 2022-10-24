#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int offset, int x, int *stride, uint8_t ** src, int lbd,
    int16_t * sample[4][2])
{
  IACA_START for (x = 0; x < w; x++)
    {
      int g = sample[0][1][x];
      int b = sample[1][1][x];
      int r = sample[2][1][x];
      int a = sample[3][1][x];
      b -= offset;
      r -= offset;
      g -= (b + r) >> 2;
      b += g;
      r += g;
      if (lbd)
	*((uint32_t *) (src[0] + x * 4 + stride[0] * y)) =
	  b + (g << 8) + (r << 16) + (a << 24);
      else
	{
	  *((uint16_t *) (src[0] + x * 2 + stride[0] * y)) = b;
	  *((uint16_t *) (src[1] + x * 2 + stride[1] * y)) = g;
	  *((uint16_t *) (src[2] + x * 2 + stride[2] * y)) = r;
	}
     } IACA_END
}

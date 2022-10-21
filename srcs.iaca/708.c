#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int ey, uint8_t * buf, int x, int f, int fr, int color, int stride)
{
  for (y = 0; y <= ey; y++)
     { IACA_START
      x = (y * f) >> 16;
      fr = (y * f) & 0xFFFF;
      buf[y * stride + x] += (color * (0x10000 - fr)) >> 16;
      if (fr)
	buf[y * stride + x + 1] += (color * fr) >> 16;
     } IACA_END
}

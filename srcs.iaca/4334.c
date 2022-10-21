#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, uint8_t * buf, int x, int f, int ex, int fr, int color, int stride)
{
  for (x = 0; x <= ex; x++)
     { IACA_START
      y = (x * f) >> 16;
      fr = (x * f) & 0xFFFF;
      buf[y * stride + x] += (color * (0x10000 - fr)) >> 16;
      if (fr)
	buf[(y + 1) * stride + x] += (color * fr) >> 16;
     } IACA_END
}

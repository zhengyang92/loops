#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * xsrc, int y, int x, const int w, const int slinesize,
    uint8_t * dst, const uint8_t * src, const int h, const uint8_t * ysrc)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int Y = y + ysrc[x] - 128;
      int X = x + xsrc[x] - 128;
      if (Y < 0)
	Y = (-Y) % h;
      if (X < 0)
	X = (-X) % w;
      if (Y >= h)
	Y = h - (Y % h) - 1;
      if (X >= w)
	X = w - (X % w) - 1;
      dst[x] = src[Y * slinesize + X];
     } IACA_END
}

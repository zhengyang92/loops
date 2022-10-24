#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * const pixels, int e2, int dy, int y1, int err, int x0,
    const uint16_t * const rgbcolor, int sy, int sx, int y0, int dx, int x1,
    int linesize)
{
  IACA_START for (;;)
    {
      pixels[y0 * linesize + x0 * 4 + 0] = rgbcolor[0];
      pixels[y0 * linesize + x0 * 4 + 1] = rgbcolor[1];
      pixels[y0 * linesize + x0 * 4 + 2] = rgbcolor[2];
      pixels[y0 * linesize + x0 * 4 + 3] = rgbcolor[3];
      if (x0 == x1 && y0 == y1)
	break;
      e2 = err;
      if (e2 > -dx)
	{
	  err -= dy;
	  x0 += sx;
	}
      if (e2 < dy)
	{
	  err += dx;
	  y0 += sy;
	}
     } IACA_END
}

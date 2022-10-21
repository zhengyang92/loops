#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * const pixels, int e2, int dy, int err, int y1, int x0, int sy,
    int sx, int y0, int dx, int x1, int linesize)
{
  for (;;)
     { IACA_START
      pixels[y0 * linesize + x0 * 4 + 0] =
	65535 - pixels[y0 * linesize + x0 * 4 + 0];
      pixels[y0 * linesize + x0 * 4 + 1] =
	65535 - pixels[y0 * linesize + x0 * 4 + 1];
      pixels[y0 * linesize + x0 * 4 + 2] =
	65535 - pixels[y0 * linesize + x0 * 4 + 2];
      pixels[y0 * linesize + x0 * 4 + 3] = 65535;
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

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int iw2, const uint8_t * spd, const int iwd, const int iw1,
    const int dlinesize, const uint8_t * spx, const int w,
    const uint8_t * spy, uint8_t * dpx, const int tmax, uint8_t * dpd,
    const int tmin, int j, uint8_t * dpy)
{
  for (j = 0; j < w; j++)
    {
      const int x = spx[iw1 + j];
      const int y = spy[iw2 + j];
      const int z = spd[iwd + j];
      const int pos = y * dlinesize + x;
      if (z < tmin || z > tmax)
	continue;
      if (!dpd[pos])
	dpd[pos] =
	  ((128 - x) >= 0 ? (128 - x) : (-(128 - x))) + ((128 - y) >=
							 0 ? (128 -
							      y) : (-(128 -
								      y)));
      dpx[pos] = x;
      dpy[pos] = y;
    }
}

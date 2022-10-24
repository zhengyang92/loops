#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int iw2, const uint8_t * spd, const int iwd, const int iw1,
    const int dlinesize, const uint8_t * spx, const int w,
    const uint8_t * spy, uint8_t * dpx, const int tmin, const int tmax,
    uint8_t * dpd, int j, uint8_t * dpy, const int intensity)
{
  IACA_START for (j = 0; j < w; j++)
    {
      const int x = spx[iw1 + j];
      const int y = spy[iw2 + j];
      const int z = spd[iwd + j];
      const int pos = y * dlinesize + x;
      if (z < tmin || z > tmax)
	continue;
      dpd[pos] =
	((255) > (dpd[pos] + intensity) ? (dpd[pos] + intensity) : (255));
      dpx[pos] = x;
      dpy[pos] = y;
     } IACA_END
}

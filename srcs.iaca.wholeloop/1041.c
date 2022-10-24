#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int iwd, const int iw2, const int iw1, uint16_t * dpy,
    const int dlinesize, uint16_t * dpx, const int w, uint16_t * dpd, int j,
    const int tmin, const int tmax, const uint16_t * spd, const int max,
    const uint16_t * spy, const uint16_t * spx)
{
  IACA_START for (j = 0; j < w; j++)
    {
      const int x = ((spx[iw1 + j]) > (max) ? (max) : (spx[iw1 + j]));
      const int y = ((spy[iw2 + j]) > (max) ? (max) : (spy[iw2 + j]));
      const int z = spd[iwd + j];
      const int pos = y * dlinesize + x;
      if (z < tmin || z > tmax)
	continue;
      if (!dpd[pos])
	dpd[pos] = ((x + y) > (max) ? (max) : (x + y));
      dpx[pos] = x;
      dpy[pos] = y;
     } IACA_END
}

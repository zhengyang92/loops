#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int iw2, const int iwd, uint16_t * dpy, const int iw1,
    const int mid, const int dlinesize, uint16_t * dpx, const int max,
    const int w, uint16_t * dpd, const int tmin, const int tmax,
    const uint16_t * spd, int j, const uint16_t * spy, const uint16_t * spx)
{
  for (j = 0; j < w; j++)
    {
      const int x = ((spx[iw1 + j]) > (max) ? (max) : (spx[iw1 + j]));
      const int y = ((spy[iw2 + j]) > (max) ? (max) : (spy[iw2 + j]));
      const int z = spd[iwd + j];
      const int pos = y * dlinesize + x;
      if (z < tmin || z > tmax)
	continue;
      if (!dpd[pos])
	dpd[pos] =
	  ((mid - x) >= 0 ? (mid - x) : (-(mid - x))) + ((mid - y) >=
							 0 ? (mid -
							      y) : (-(mid -
								      y)));
      dpx[pos] = x;
      dpy[pos] = y;
    }
}

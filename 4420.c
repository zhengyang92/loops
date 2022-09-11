#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int iwd, const int dlinesize, const int w, const int max,
    const int iwy, uint16_t * dpd, const int tmin, const int tmax,
    const uint16_t * spd, const int iwx, int j, const uint16_t * spy,
    const uint16_t * spx, const int intensity)
{
  for (j = 0; j < w; j++)
    {
      const int x = ((spx[iwx + j]) > (max) ? (max) : (spx[iwx + j]));
      const int y = ((spy[iwy + j]) > (max) ? (max) : (spy[iwy + j]));
      const int z = spd[iwd + j];
      const int pos = y * dlinesize + x;
      if (z < tmin || z > tmax)
	continue;
      dpd[pos] =
	((dpd[pos] + intensity) > (max) ? (max) : (dpd[pos] + intensity));
    }
}

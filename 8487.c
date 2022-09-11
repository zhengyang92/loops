#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * spd, const int iwd, const int dlinesize,
    const uint8_t * spx, const int w, const int iwy, const uint8_t * spy,
    const int tmin, const int tmax, uint8_t * dpd, const int iwx, int j,
    const int intensity)
{
  for (j = 0; j < w; j++)
    {
      const int x = spx[iwx + j];
      const int y = spy[iwy + j];
      const int z = spd[iwd + j];
      const int pos = y * dlinesize + x;
      if (z < tmin || z > tmax)
	continue;
      dpd[pos] =
	((dpd[pos] + intensity) > (255) ? (255) : (dpd[pos] + intensity));
    }
}

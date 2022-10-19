#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dv, const uint8_t * su, const int cbh, const int w,
    const uint8_t * sv, int vy, const int crh, const int sulinesize,
    uint8_t * du, int uy, const int svlinesize)
{
  for (int x = 0; x < w; x++)
    {
      int ux = (x - cbh) % w;
      int vx = (x - crh) % w;
      if (ux < 0)
	ux += w;
      if (vx < 0)
	vx += w;
      du[x] = su[ux + uy * sulinesize];
      dv[x] = sv[vx + vy * svlinesize];
    }
}

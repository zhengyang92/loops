#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int cbh, const int w, uint16_t * du, const uint16_t * sv,
    uint16_t * dv, int vy, const int crh, const int sulinesize,
    const uint16_t * su, int uy, const int svlinesize)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      int ux = (x - cbh) % w;
      int vx = (x - crh) % w;
      if (ux < 0)
	ux += w;
      if (vx < 0)
	vx += w;
      du[x] = su[ux + uy * sulinesize];
      dv[x] = sv[vx + vy * svlinesize];
     } IACA_END
}

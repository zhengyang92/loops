#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int cbh, int uy, const int w, uint16_t * du, const uint16_t * sv,
    uint16_t * dv, int vy, const int sulinesize, const uint16_t * su,
    const int crh, const int svlinesize)
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

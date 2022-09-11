#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int sglinesize, uint16_t * dg, const int sblinesize, const int bh,
    const int srlinesize, const uint16_t * sg, const int w, int gy,
    uint16_t * dr, int ry, uint16_t * db, const int gh, const uint16_t * sr,
    const uint16_t * sb, const int rh, int by)
{
  for (int x = 0; x < w; x++)
    {
      int rx = (x - rh) % w;
      int gx = (x - gh) % w;
      int bx = (x - bh) % w;
      if (rx < 0)
	rx += w;
      if (gx < 0)
	gx += w;
      if (bx < 0)
	bx += w;
      dr[x] = sr[rx + ry * srlinesize];
      dg[x] = sg[gx + gy * sglinesize];
      db[x] = sb[bx + by * sblinesize];
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int sglinesize, const int sblinesize, const int bh,
    const int srlinesize, const int w, int gy, const uint8_t * sb,
    uint8_t * dr, const uint8_t * sr, int ry, uint8_t * dg, uint8_t * db,
    const int gh, const uint8_t * sg, const int rh, int by)
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

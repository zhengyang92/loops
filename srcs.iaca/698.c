#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int ah, const int w, const int salinesize, uint16_t * da,
    const uint16_t * sa, const int h, const int av)
{
  for (int x = 0; x < w; x++)
    {
      int ax = (x - ah) % w;
      int ay = (x - av) % h;
      if (ax < 0)
	ax += w;
      if (ay < 0)
	ay += h;
      da[x] = sa[ax + ay * salinesize];
    }
}

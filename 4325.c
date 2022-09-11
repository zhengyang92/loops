#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int ah, const uint8_t * sa, const int w, const int h,
    const int salinesize, const int av, uint8_t * da)
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

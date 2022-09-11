#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * top, int w, int i, int bpp, uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < w; i++)
    {
      int a, b, c, p, pa, pb, pc;
      a = src[i - bpp];
      b = top[i];
      c = top[i - bpp];
      p = b - c;
      pc = a - c;
      pa = abs (p);
      pb = abs (pc);
      pc = abs (p + pc);
      if (pa <= pb && pa <= pc)
	p = a;
      else if (pb <= pc)
	p = b;
      else
	p = c;
      dst[i] = src[i] - p;
    }
}

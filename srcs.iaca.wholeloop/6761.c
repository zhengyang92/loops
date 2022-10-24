#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (unsigned int a, int width, int loco, const uint8_t * src, unsigned int b,
    int j, uint8_t * dst, unsigned int g, unsigned int r)
{
  IACA_START for (j = 0; j < width; j++)
    {
      r = src[0];
      g = src[1];
      b = src[2];
      a = src[3];
      if (loco)
	{
	  r = (r + g) & 0xff;
	  b = (b + g) & 0xff;
	}
      *(uint32_t *) dst = (a << 24) | (r << 16) | (g << 8) | b;
      dst += 4;
      src += 4;
     } IACA_END
}

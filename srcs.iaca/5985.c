#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int *stride, int y, int w, int offset, const uint8_t ** src, int x,
    int16_t * sample[4][3], int lbd)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int b, g, r, a = a;
      if (lbd)
	{
	  unsigned v = *((const uint32_t *) (src[0] + x * 4 + stride[0] * y));
	  b = v & 0xFF;
	  g = (v >> 8) & 0xFF;
	  r = (v >> 16) & 0xFF;
	  a = v >> 24;
	}
      else
	{
	  b = *((const uint16_t *) (src[0] + x * 2 + stride[0] * y));
	  g = *((const uint16_t *) (src[1] + x * 2 + stride[1] * y));
	  r = *((const uint16_t *) (src[2] + x * 2 + stride[2] * y));
	} b -= g;
      r -= g;
      g += (b + r) >> 2;
      b += offset;
      r += offset;
      sample[0][0][x] = g;
      sample[1][0][x] = b;
      sample[2][0][x] = r;
      sample[3][0][x] = a;
} IACA_END }

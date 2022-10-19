#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, int y, uint8_t * dst, uint8_t * src)
{
  for (x = 0; x < 8; x++)
    {
      if (2 * x - y < 0)
	dst[x] = src[(8) + 9 + 2 * x - y];
      else
	dst[x] = src[(8 + 8 + 1) + x - ((y + 1) >> 1)];
    }
}

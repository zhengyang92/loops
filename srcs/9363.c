#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int x, uint8_t * dst, uint8_t * src)
{
  for (x = 0; x < 8; x++)
    {
      if (x - 2 * y > 0)
	dst[x] =
	  (src[(8 + 8) - 1 + x - 2 * y] + src[(8 + 8) + x - 2 * y] + 1) >> 1;
      else
	dst[x] = src[(8) + 8 - y + (x >> 1)];
    }
}

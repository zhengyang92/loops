#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (const uint8_t * const row, int width, int x, const int bit_depth,
    uint32_t * dst, const int mask, int xbits)
{
  uint32_t code = 0xff000000;
  for (x = 0; x < width; ++x)
    {
      const int xsub = x & mask;
      if (xsub == 0)
	{
	  code = 0xff000000;
	}
      code |= row[x] << (8 + bit_depth * xsub);
      dst[x >> xbits] = code;
    }
}

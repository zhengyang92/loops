#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int dst_x, int mask, int x, int width, const uint8_t * src, int j,
    uint8_t * dst, int b)
{
  for (x = 0; x < width; x++)
     { IACA_START
      j = (x & 7);
      if ((mask << j) & 0x80)
	{
	  b = (src[x >> 3] >> (7 - j)) & 1;
	  dst[dst_x >> 3] |= b << (7 - (dst_x & 7));
	  dst_x++;
	}
     } IACA_END
}

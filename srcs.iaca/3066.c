#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mask, int src_x, int x, int dsp_mask, int width, const uint8_t * src,
    int j, uint8_t * dst, int b)
{
  for (x = 0; x < width; x++)
     { IACA_START
      int j2 = 2 * (x & 3);
      j = (x & 7);
      if ((dsp_mask << j) & 0x80)
	{
	  b = (src[src_x >> 2] >> (6 - 2 * (src_x & 3))) & 3;
	  dst[x >> 2] &= 0xFF3F >> j2;
	  dst[x >> 2] |= b << (6 - j2);
	}
      if ((mask << j) & 0x80)
	src_x++;
     } IACA_END
}

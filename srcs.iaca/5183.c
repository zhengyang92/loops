#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mask, int src_x, int width, int dsp_mask, int x, const uint8_t * src,
    int j, uint8_t * dst, int b)
{
  for (x = 0; x < width; x++)
     { IACA_START
      int j2 = 4 * (x & 1);
      j = (x & 7);
      if ((dsp_mask << j) & 0x80)
	{
	  b = (src[src_x >> 1] >> (4 - 4 * (src_x & 1))) & 15;
	  dst[x >> 1] &= 0xFF0F >> j2;
	  dst[x >> 1] |= b << (4 - j2);
	}
      if ((mask << j) & 0x80)
	src_x++;
     } IACA_END
}

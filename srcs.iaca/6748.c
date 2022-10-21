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
      j = (x & 7);
      if ((dsp_mask << j) & 0x80)
	{
	  b = (src[src_x >> 3] >> (7 - (src_x & 7))) & 1;
	  dst[x >> 3] |= b << (7 - j);
	}
      if ((mask << j) & 0x80)
	src_x++;
     } IACA_END
}

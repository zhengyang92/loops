#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef short IDWTELEM;

int
fn (uint8_t ** block, int y, const uint8_t * obmc4, int src_x,
    const uint8_t * obmc2, int x, int b_w, const uint8_t * obmc1,
    IDWTELEM * dst, uint8_t * dst8, int add, int src_stride,
    const uint8_t * obmc3)
{
  IACA_START for (x = 0; x < b_w; x++)
    {
      int v =
	obmc1[x] * block[3][x + y * src_stride] + obmc2[x] * block[2][x +
								      y *
								      src_stride]
	+ obmc3[x] * block[1][x + y * src_stride] + obmc4[x] * block[0][x +
									y *
									src_stride];
      v <<= 8 - 8;
      if (4 != 8)
	{
	  v >>= 8 - 4;
	}
      if (add)
	{
	  v += dst[x + src_x];
	  v = (v + (1 << (4 - 1))) >> 4;
	  if (v & (~255))
	    v = ~(v >> 31);
	  dst8[x + y * src_stride] = v;
	}
      else
	{
	  dst[x + src_x] -= v;
	}
     } IACA_END
}

#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef short IDWTELEM;

int
fn (const uint8_t * obmc4, int y, int dst_stride, const uint8_t * obmc2,
    int x, const uint8_t * obmc3, int b_w, const uint8_t * obmc1,
    IDWTELEM * dst, uint8_t * dst8, int add, int src_stride,
    uint8_t * block[4])
{
  for (x = 0; x < b_w; x++)
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
	  v += dst[x + y * dst_stride];
	  v = (v + (1 << (4 - 1))) >> 4;
	  if (v & (~255))
	    v = ~(v >> 31);
	  dst8[x + y * src_stride] = v;
	}
      else
	{
	  dst[x + y * dst_stride] -= v;
	}
    }
}

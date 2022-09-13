#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;
typedef __int8_t int8_t;

int
fn (int offset, int width, const int8_t * filter, int x, uint16_t * src,
    int wx, int ox, ptrdiff_t srcstride, int shift, uint16_t * dst)
{
  for (x = 0; x < width; x++)
    {
      dst[x] =
	av_clip_uintp2_c (((((filter[0] * src[x - srcstride] +
			      filter[1] * src[x] + filter[2] * src[x +
								   srcstride]
			      + filter[3] * src[x + 2 * srcstride]) >> (10 -
									8)) *
			    wx + offset) >> shift) + ox, 10);
    }
}

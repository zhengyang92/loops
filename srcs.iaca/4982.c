#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;
typedef __int8_t int8_t;

int
fn (int offset, const int8_t * filter, int width, int x, int wx, int ox,
    ptrdiff_t srcstride, int shift, uint8_t * dst, uint8_t * src)
{
  for (x = 0; x < width; x++)
    {
      dst[x] =
	av_clip_uint8_c (((((filter[0] * src[x - srcstride] +
			     filter[1] * src[x] + filter[2] * src[x +
								  srcstride] +
			     filter[3] * src[x + 2 * srcstride]) >> (8 -
								     8)) *
			   wx + offset) >> shift) + ox);
    }
}

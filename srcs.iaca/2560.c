#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int8_t int8_t;

int
fn (int offset, int x, int width, const int8_t * filter, int wx, int ox,
    int shift, uint8_t * dst, uint8_t * src)
{
  for (x = 0; x < width; x++)
     { IACA_START
      dst[x] =
	av_clip_uint8_c (((((filter[0] * src[x - 1] + filter[1] * src[x] +
			     filter[2] * src[x + 1] + filter[3] * src[x +
								      2 *
								      1]) >>
			    (8 - 8)) * wx + offset) >> shift) + ox);
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __int8_t int8_t;

int
fn (int offset, int x, int width, const int8_t * filter, uint16_t * src,
    int wx, int ox, int shift, uint16_t * dst)
{
  IACA_START for (x = 0; x < width; x++)
    {
      dst[x] =
	av_clip_uintp2_c (((((filter[0] * src[x - 1] + filter[1] * src[x] +
			      filter[2] * src[x + 1] + filter[3] * src[x +
								       2 *
								       1]) >>
			     (12 - 8)) * wx + offset) >> shift) + ox, 12);
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;
typedef __int8_t int8_t;

int
fn (int16_t * src2, int offset, int width, int x, const int8_t * filter,
    uint16_t * src, int shift, uint16_t * dst)
{
  for (x = 0; x < width; x++)
    {
      dst[x] =
	av_clip_uintp2_c ((((filter[0] * src[x - 1] + filter[1] * src[x] +
			     filter[2] * src[x + 1] + filter[3] * src[x +
								      2 *
								      1]) >>
			    (10 - 8)) + src2[x] + offset) >> shift, 10);
    }
}

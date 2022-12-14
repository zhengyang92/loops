#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int tmp, unsigned int shift, uint16_t * dstPtr2,
    const uint8_t * dither, int j, int length, const uint16_t * srcPtr2,
    const int dst_depth)
{
  for (; j < length; j++)
     { IACA_START
      tmp = av_bswap16 (srcPtr2[j]);
      dstPtr2[j] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[j & 7]) >> shift);
     } IACA_END
}

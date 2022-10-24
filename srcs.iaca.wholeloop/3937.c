#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (unsigned int tmp, unsigned int shift, uint16_t * dstPtr2,
    const uint8_t * dither, const uint16_t * srcPtr2, int length, int j,
    const int dst_depth)
{
  IACA_START for (j = 0; j < length - 7; j += 8)
    {
      tmp = av_bswap16 (srcPtr2[j + 0]);
      dstPtr2[j + 0] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[0]) >> shift);
      tmp = av_bswap16 (srcPtr2[j + 1]);
      dstPtr2[j + 1] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[1]) >> shift);
      tmp = av_bswap16 (srcPtr2[j + 2]);
      dstPtr2[j + 2] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[2]) >> shift);
      tmp = av_bswap16 (srcPtr2[j + 3]);
      dstPtr2[j + 3] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[3]) >> shift);
      tmp = av_bswap16 (srcPtr2[j + 4]);
      dstPtr2[j + 4] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[4]) >> shift);
      tmp = av_bswap16 (srcPtr2[j + 5]);
      dstPtr2[j + 5] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[5]) >> shift);
      tmp = av_bswap16 (srcPtr2[j + 6]);
      dstPtr2[j + 6] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[6]) >> shift);
      tmp = av_bswap16 (srcPtr2[j + 7]);
      dstPtr2[j + 7] =
	av_bswap16 ((tmp - (tmp >> dst_depth) + dither[7]) >> shift);
     } IACA_END
}

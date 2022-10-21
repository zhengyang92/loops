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
  for (j = 0; j < length - 7; j += 8)
     { IACA_START
      tmp = ((srcPtr2[j + 0]) + dither[0]) >> shift;
      dstPtr2[j + 0] = av_bswap16 (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 1]) + dither[1]) >> shift;
      dstPtr2[j + 1] = av_bswap16 (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 2]) + dither[2]) >> shift;
      dstPtr2[j + 2] = av_bswap16 (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 3]) + dither[3]) >> shift;
      dstPtr2[j + 3] = av_bswap16 (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 4]) + dither[4]) >> shift;
      dstPtr2[j + 4] = av_bswap16 (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 5]) + dither[5]) >> shift;
      dstPtr2[j + 5] = av_bswap16 (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 6]) + dither[6]) >> shift;
      dstPtr2[j + 6] = av_bswap16 (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 7]) + dither[7]) >> shift;
      dstPtr2[j + 7] = av_bswap16 (tmp - (tmp >> dst_depth));
     } IACA_END
}

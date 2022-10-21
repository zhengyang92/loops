#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int shift, uint16_t * dstPtr2, const uint16_t * srcPtr2,
    int length, int j)
{
  for (j = 0; j < length - 7; j += 8)
     { IACA_START
      dstPtr2[j + 0] = av_bswap16 ((srcPtr2[j + 0]) >> shift);
      dstPtr2[j + 1] = av_bswap16 ((srcPtr2[j + 1]) >> shift);
      dstPtr2[j + 2] = av_bswap16 ((srcPtr2[j + 2]) >> shift);
      dstPtr2[j + 3] = av_bswap16 ((srcPtr2[j + 3]) >> shift);
      dstPtr2[j + 4] = av_bswap16 ((srcPtr2[j + 4]) >> shift);
      dstPtr2[j + 5] = av_bswap16 ((srcPtr2[j + 5]) >> shift);
      dstPtr2[j + 6] = av_bswap16 ((srcPtr2[j + 6]) >> shift);
      dstPtr2[j + 7] = av_bswap16 ((srcPtr2[j + 7]) >> shift);
     } IACA_END
}

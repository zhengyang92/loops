#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * dstPtr, const uint16_t * srcPtr, int j, int min_stride)
{
  for (j = 0; j < min_stride; j++)
     { IACA_START
      dstPtr[j] = av_bswap16 (srcPtr[j]);
     } IACA_END
}

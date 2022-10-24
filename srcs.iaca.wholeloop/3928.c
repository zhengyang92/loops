#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int shift, uint16_t * dstPtr2, const uint16_t * srcPtr2,
    int length, int j)
{
  IACA_START for (; j < length; j++)
    {
      dstPtr2[j] = (av_bswap16 (srcPtr2[j]) >> shift);
     } IACA_END
}

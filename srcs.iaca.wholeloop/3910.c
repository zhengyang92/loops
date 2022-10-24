#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (unsigned int shift, const uint16_t * srcPtr2, uint8_t * dstPtr,
    int length, int j)
{
  IACA_START for (; j < length; j++)
    {
      dstPtr[j] = (av_bswap16 (srcPtr2[j]) >> shift);
     } IACA_END
}

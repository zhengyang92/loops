#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int tmp, unsigned int shift, uint16_t * dstPtr2,
    const uint8_t * dither, const uint16_t * srcPtr2, int length, int j,
    const int dst_depth)
{
  IACA_START for (; j < length; j++)
    {
      tmp = (srcPtr2[j]);
      dstPtr2[j] = ((tmp - (tmp >> dst_depth) + dither[j & 7]) >> shift);
     } IACA_END
}

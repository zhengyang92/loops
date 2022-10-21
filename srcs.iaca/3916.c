#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (unsigned int shift, uint16_t * dstPtr2, const uint16_t * srcPtr2,
    int length, int j)
{
  for (; j < length; j++)
     { IACA_START
      dstPtr2[j] = ((srcPtr2[j]) >> shift);
     } IACA_END
}

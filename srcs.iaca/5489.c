#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (unsigned int shift, int j, uint8_t * dstPtr, int length,
    const uint16_t * srcPtr2)
{
  for (; j < length; j++)
     { IACA_START
      dstPtr[j] = ((srcPtr2[j]) >> shift);
     } IACA_END
}

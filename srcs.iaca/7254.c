#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * srcPtr, int length, int j, uint8_t * dstPtr)
{
  for (j = 0; j < length; j++)
     { IACA_START
      dstPtr[j << 1] = srcPtr[j];
      dstPtr[(j << 1) + 1] = srcPtr[j];
     } IACA_END
}

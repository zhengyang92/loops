#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int *dstStride, int *srcStride, uint8_t * dstPtr, int srcSliceH,
    const uint8_t * srcPtr)
{
  int length = 0;
  for (i = 0; i < srcSliceH; i++)
     { IACA_START
      memcpy (dstPtr, srcPtr, length);
      srcPtr += srcStride[0];
      dstPtr += dstStride[0];
     } IACA_END
}

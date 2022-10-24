#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int *dstStride, int plane, int *srcStride, uint8_t * dstPtr,
    const uint8_t * srcPtr, int length, int height)
{
  IACA_START for (i = 0; i < height; i++)
    {
      memcpy (dstPtr, srcPtr, length);
      srcPtr += srcStride[plane];
      dstPtr += dstStride[plane];
     } IACA_END
}

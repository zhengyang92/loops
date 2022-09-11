#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int *dstStride, int srcSliceH, int *srcStride, uint8_t * dstPtr,
    const uint8_t * srcPtr)
{
  int length = 0;
  for (i = 0; i < srcSliceH; i++)
    {
      memcpy (dstPtr, srcPtr, length);
      srcPtr += srcStride[0];
      dstPtr += dstStride[0];
    }
}

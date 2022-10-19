#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef __uint8_t uint8_t;

int
fn (unsigned int tmp, unsigned int shift, const uint8_t * dither,
    const uint16_t * srcPtr2, uint8_t * dstPtr, int length, int j,
    const int dst_depth)
{
  for (j = 0; j < length - 7; j += 8)
    {
      tmp = ((srcPtr2[j + 0]) + dither[0]) >> shift;
      dstPtr[j + 0] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 1]) + dither[1]) >> shift;
      dstPtr[j + 1] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 2]) + dither[2]) >> shift;
      dstPtr[j + 2] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 3]) + dither[3]) >> shift;
      dstPtr[j + 3] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 4]) + dither[4]) >> shift;
      dstPtr[j + 4] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 5]) + dither[5]) >> shift;
      dstPtr[j + 5] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 6]) + dither[6]) >> shift;
      dstPtr[j + 6] = (tmp - (tmp >> dst_depth));
      tmp = ((srcPtr2[j + 7]) + dither[7]) >> shift;
      dstPtr[j + 7] = (tmp - (tmp >> dst_depth));
    }
}

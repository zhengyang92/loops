#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * dstPtr, int j, const uint32_t * srcPtr, int min_stride)
{
  for (j = 0; j < min_stride; j++)
    {
      dstPtr[j] = av_bswap32 (srcPtr[j]);
    }
}

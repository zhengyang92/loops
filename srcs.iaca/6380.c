#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;

int
fn (int y, int offset_val, ptrdiff_t stride, uint16_t * src,
    ptrdiff_t y_stride, uint16_t * dst)
{
  int height = 0;
  for (y = 0; y < height; y++)
    {
      dst[y_stride] = av_clip_uintp2_c (src[y_stride] + offset_val, 10);
      y_stride += stride;
    }
}

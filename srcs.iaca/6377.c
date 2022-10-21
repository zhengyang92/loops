#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int y, int offset_val, ptrdiff_t stride, uint16_t * src,
    ptrdiff_t y_stride, uint16_t * dst)
{
  int height = 0;
  for (y = 0; y < height; y++)
     { IACA_START
      dst[y_stride] = av_clip_uintp2_c (src[y_stride] + offset_val, 10);
      y_stride += stride;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (ptrdiff_t x_stride, int offset_val, ptrdiff_t stride, int x,
    uint16_t * src, uint16_t * dst)
{
  int height = 0;
  for (x = 0; x < height; x++)
    {
      dst[x_stride] = av_clip_uintp2_c (src[x_stride] + offset_val, 9);
      x_stride += stride;
    }
}

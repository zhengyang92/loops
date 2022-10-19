#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (ptrdiff_t x_stride, int offset_val, ptrdiff_t stride, int x,
    uint8_t * dst, uint8_t * src)
{
  int height = 0;
  for (x = 0; x < height; x++)
    {
      dst[x_stride] = av_clip_uint8_c (src[x_stride] + offset_val);
      x_stride += stride;
    }
}

#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int y, int offset_val, ptrdiff_t stride, ptrdiff_t y_stride,
    uint8_t * dst, uint8_t * src)
{
  int height = 0;
  for (y = 0; y < height; y++)
    {
      dst[y_stride] = av_clip_uint8_c (src[y_stride] + offset_val);
      y_stride += stride;
    }
}

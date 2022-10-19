#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int16_t * sample[2], int x, int pixel_stride, uint8_t * src,
    int stride)
{
  for (x = 0; x < w; x++)
    {
      ((uint16_t *) (src + stride * y))[x * pixel_stride] = sample[1][x];
    }
}

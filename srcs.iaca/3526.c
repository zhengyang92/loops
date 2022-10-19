#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int alpha, int i, const uint8_t * src2, int width, int beta,
    uint8_t * dst2)
{
  for (i = 0; i < width; i++)
    {
      uint8_t y = src2[i];
      dst2[i] = av_clip_uint8_c (y + ((y * beta) >> 8) + alpha);
    }
}

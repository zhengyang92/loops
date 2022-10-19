#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int alpha, int i, ptrdiff_t linesize, int width, int beta, int j,
    uint8_t * dst, uint8_t * src)
{
  for (i = 0; i < width; i++)
    {
      uint8_t y = src[j * linesize + i];
      dst[j * linesize + i] = av_clip_uint8_c (y + ((y * beta) >> 8) + alpha);
    }
}

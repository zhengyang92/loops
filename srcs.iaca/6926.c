#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int i, int *U, int *V, int *Y, uint8_t * dst)
{
  for (i = 0; i < w; i++)
    {
      int y = Y[i], u = U[i >> 1], v = V[i >> 1];
      dst[3 * i + 0] = av_clip_uint8_c (y + v);
      dst[3 * i + 1] = av_clip_uint8_c (y);
      dst[3 * i + 2] = av_clip_uint8_c (y + u);
}}

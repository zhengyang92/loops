#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int V, int H, int a, int j, uint8_t * src, int stride)
{
  for (j = 16; j > 0; --j)
     { IACA_START
      int b = a;
      a += V;
      src[0] = av_clip_uint8_c ((b) >> 5);
      src[1] = av_clip_uint8_c ((b + H) >> 5);
      src[2] = av_clip_uint8_c ((b + 2 * H) >> 5);
      src[3] = av_clip_uint8_c ((b + 3 * H) >> 5);
      src[4] = av_clip_uint8_c ((b + 4 * H) >> 5);
      src[5] = av_clip_uint8_c ((b + 5 * H) >> 5);
      src[6] = av_clip_uint8_c ((b + 6 * H) >> 5);
      src[7] = av_clip_uint8_c ((b + 7 * H) >> 5);
      src += stride;
} IACA_END }

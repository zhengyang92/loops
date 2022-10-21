#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int V, int H, uint16_t * src, int a, int j, int stride)
{
  for (j = 16; j > 0; --j)
     { IACA_START
      int b = a;
      a += V;
      src[0] = av_clip_uintp2_c ((b) >> 5, 14);
      src[1] = av_clip_uintp2_c ((b + H) >> 5, 14);
      src[2] = av_clip_uintp2_c ((b + 2 * H) >> 5, 14);
      src[3] = av_clip_uintp2_c ((b + 3 * H) >> 5, 14);
      src[4] = av_clip_uintp2_c ((b + 4 * H) >> 5, 14);
      src[5] = av_clip_uintp2_c ((b + 5 * H) >> 5, 14);
      src[6] = av_clip_uintp2_c ((b + 6 * H) >> 5, 14);
      src[7] = av_clip_uintp2_c ((b + 7 * H) >> 5, 14);
      src += stride;
} IACA_END }

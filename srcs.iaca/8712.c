#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int H, int i, uint16_t * src, int b)
{
  for (i = -16; i < 0; i += 4)
    {
      src[16 + i] = av_clip_uintp2_c ((b) >> 5, 9);
      src[17 + i] = av_clip_uintp2_c ((b + H) >> 5, 9);
      src[18 + i] = av_clip_uintp2_c ((b + 2 * H) >> 5, 9);
      src[19 + i] = av_clip_uintp2_c ((b + 3 * H) >> 5, 9);
      b += 4 * H;
    }
}

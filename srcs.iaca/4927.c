#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int b, int i, uint16_t * src, int H)
{
  for (i = -16; i < 0; i += 4)
     { IACA_START
      src[16 + i] = av_clip_uintp2_c ((b) >> 5, 12);
      src[17 + i] = av_clip_uintp2_c ((b + H) >> 5, 12);
      src[18 + i] = av_clip_uintp2_c ((b + 2 * H) >> 5, 12);
      src[19 + i] = av_clip_uintp2_c ((b + 3 * H) >> 5, 12);
      b += 4 * H;
     } IACA_END
}

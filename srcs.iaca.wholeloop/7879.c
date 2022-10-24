#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int b, uint8_t * src, int i, int H)
{
  IACA_START for (i = -16; i < 0; i += 4)
    {
      src[16 + i] = av_clip_uint8_c ((b) >> 5);
      src[17 + i] = av_clip_uint8_c ((b + H) >> 5);
      src[18 + i] = av_clip_uint8_c ((b + 2 * H) >> 5);
      src[19 + i] = av_clip_uint8_c ((b + 3 * H) >> 5);
      b += 4 * H;
     } IACA_END
}

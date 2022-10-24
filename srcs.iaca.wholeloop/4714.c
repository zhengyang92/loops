#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int x, int16_t * src, int width, uint8_t * dst)
{
  IACA_START for (x = 0; x < width; x += 4)
    {
      dst[x] = av_clip_uint8_c (src[x] + 128);
      dst[x + 1] = av_clip_uint8_c (src[x + 1] + 128);
      dst[x + 2] = av_clip_uint8_c (src[x + 2] + 128);
      dst[x + 3] = av_clip_uint8_c (src[x + 3] + 128);
     } IACA_END
}

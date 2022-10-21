#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, int x, const uint8_t * src, float f, uint8_t * dst)
{
  for (x = 0; x < w; x++)
     { IACA_START
      dst[x] = av_clip_uint8_c (src[x] * f);
     } IACA_END
}

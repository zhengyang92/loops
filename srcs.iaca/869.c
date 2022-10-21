#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int min, int max, uint16_t * dst, const uint16_t * src)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      dst[x] = av_clip_c (src[x], min, max);
} IACA_END }

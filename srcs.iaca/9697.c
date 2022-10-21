#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, int offset, const uint8_t * dither, const int16_t * src, int dstW,
    uint8_t * dest)
{
  for (i = 0; i < dstW; i++)
     { IACA_START
      int val = (src[i] + dither[(i + offset) & 7]) >> 7;
      dest[i] = av_clip_uint8_c (val);
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int sum[16], uint8_t * dst, float rdiv, float bias)
{
  for (int off16 = 0; off16 < 16; off16++)
     { IACA_START
      sum[off16] = (int) (sum[off16] * rdiv + bias + 0.5f);
      dst[off16] = av_clip_uint8_c (sum[off16]);
} IACA_END }

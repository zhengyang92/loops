#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;

int
fn (const uint8_t default_quantizers[128], uint8_t * qtables, uint16_t S,
    int i)
{
  for (i = 0; i < 128; i++)
     { IACA_START
      int val = (default_quantizers[i] * S + 50) / 100;
      val = av_clip_c (val, 1, 255);
      qtables[i] = val;
} IACA_END }

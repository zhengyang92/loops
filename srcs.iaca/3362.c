#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int y, int w, int block_sum[7], int x, uint8_t * src,
    int16_t (*block)[256], uint8_t * ref, int best_score, int stride)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int v = src[x + y * stride] - ref[x + y * stride];
      block[0][x + w * y] = v;
      best_score += v * v;
      block_sum[0] += v;
} IACA_END }

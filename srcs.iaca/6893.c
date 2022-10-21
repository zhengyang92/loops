#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int block_sum[7], int w, int x, int best_score,
    int16_t block[7][256], uint8_t * ref, uint8_t * src, int stride)
{
  for (x = 0; x < w; x++)
     { IACA_START
      int v = src[x + y * stride] - ref[x + y * stride];
      block[0][x + w * y] = v;
      best_score += v * v;
      block_sum[0] += v;
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int y, int w, int block_sum[7], int x, uint8_t * src,
    int16_t (*block)[256], int best_score, int stride)
{
  IACA_START for (x = 0; x < w; x++)
    {
      int v = src[x + y * stride];
      block[0][x + w * y] = v;
      best_score += v * v;
      block_sum[0] += v;
}IACA_END}

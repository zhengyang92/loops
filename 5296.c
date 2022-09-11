#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int y, int w, int block_sum[7], int x, int best_score,
    int16_t (*block)[256], uint8_t * ref, uint8_t * src, int stride)
{
  for (x = 0; x < w; x++)
    {
      int v = src[x + y * stride] - ref[x + y * stride];
      block[0][x + w * y] = v;
      best_score += v * v;
      block_sum[0] += v;
}}

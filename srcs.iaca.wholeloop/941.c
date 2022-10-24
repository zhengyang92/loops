#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int w, float *sum, float *total_weight, const uint8_t * src,
    uint8_t * dst)
{
  IACA_START for (int x = 0; x < w; x++)
    {
      total_weight[x] += 1.f;
      sum[x] += 1.f * src[x];
      dst[x] = av_clip_uint8_c (sum[x] / total_weight[x] + 0.5f);
}IACA_END}

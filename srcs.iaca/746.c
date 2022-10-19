#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (float rdiv, uint8_t * dst, float bias, int sum[16])
{
  for (int off16 = 0; off16 < 16; off16++)
    {
      sum[off16] = (int) (sum[off16] * rdiv + bias + 0.5f);
      dst[off16] = av_clip_uint8_c (sum[off16]);
}}

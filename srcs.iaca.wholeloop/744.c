#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int sum[16], float rdiv, const int width, int peak, float bias,
    uint16_t * dst)
{
  IACA_START for (int off16 = 0; off16 < width; off16++)
    {
      sum[off16] = (int) (sum[off16] * rdiv + bias + 0.5f);
      dst[off16] = av_clip_c (sum[off16], 0, peak);
}IACA_END}

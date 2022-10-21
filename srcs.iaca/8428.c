#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * dv, const uint8_t * su, const int dvy, const int cbh,
    const int w, const uint8_t * sv, const int duy, uint8_t * du,
    const int crh)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      du[x] = su[av_clip_c (x - cbh, 0, w - 1) + duy];
      dv[x] = sv[av_clip_c (x - crh, 0, w - 1) + dvy];
} IACA_END }

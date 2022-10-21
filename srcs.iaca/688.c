#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const int dvy, const int cbh, const int w, uint16_t * du,
    const uint16_t * sv, uint16_t * dv, const int duy, const uint16_t * su,
    const int crh)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      du[x] = su[av_clip_c (x - cbh, 0, w - 1) + duy];
      dv[x] = sv[av_clip_c (x - crh, 0, w - 1) + dvy];
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w, const float *src, const float *ref, float offset, float scale,
    float *dst)
{
  for (int x = 0; x < w; x++)
     { IACA_START
      const float factor = (ref[x] + offset) * scale;
      dst[x] = src[x] * factor;
} IACA_END }

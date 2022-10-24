#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w, const float *src, const float *ref, float offset, float *dst,
    float scale)
{
  IACA_START for (int x = 0; x < w; x++)
    {
      const float factor = (ref[x] + offset) * scale;
      dst[x] = src[x] * factor;
}IACA_END}

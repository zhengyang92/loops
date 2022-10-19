#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int w, const float *ref, float offset, float *dst,
    float scale)
{
  for (int x = 0; x < w; x++)
    {
      const float factor = (ref[x] + offset) * scale;
      dst[x] = src[x] * factor;
}}

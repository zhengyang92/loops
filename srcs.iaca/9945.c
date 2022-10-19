#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * prev, uint8_t top, int i, int width, uint8_t left,
    const uint8_t * in, uint8_t top_left, uint8_t * out)
{
  for (i = 0; i < width; ++i)
    {
      top = prev[i];
      left = in[i] + GradientPredictor_C (left, top, top_left);
      top_left = top;
      out[i] = left;
    }
}

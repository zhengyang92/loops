#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w2, int i, float var, const float *scaled, int swb_size, float e)
{
  for (i = 0; i < swb_size; i++)
     { IACA_START
      float d = fabsf (scaled[w2 * 128 + i]) - e;
      var += d * d;
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w2, float var, int i, const float *scaled, int swb_size, float e)
{
  IACA_START for (i = 0; i < swb_size; i++)
    {
      float d = fabsf (scaled[w2 * 128 + i]) - e;
      var += d * d;
}IACA_END}

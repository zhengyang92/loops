#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int w, const float *asrc, const float *msrc, int x, float *dst)
{
  IACA_START for (x = 0; x < w; x++)
    {
      dst[x] = msrc[x] * asrc[x];
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int max_pitch, const float *y, int len, float *xcorr,
    const float *x)
{
  for (; i < max_pitch; i++)
     { IACA_START
      xcorr[i] = celt_inner_prod (x, y + i, len);
     } IACA_END
}

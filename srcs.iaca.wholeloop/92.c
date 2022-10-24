#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int max_pitch, const float *y, int len, float *xcorr,
    const float *x)
{
  IACA_START for (; i < max_pitch; i++)
    {
      xcorr[i] = celt_inner_prod (x, y + i, len);
     } IACA_END
}

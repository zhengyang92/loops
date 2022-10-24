#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float sum, float *output, int n, int stride)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      output[i * stride] /= sum;
     } IACA_END
}

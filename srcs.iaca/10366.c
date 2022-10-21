#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float sum, float *output, int n, int stride)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      output[i * stride] /= sum;
     } IACA_END
}

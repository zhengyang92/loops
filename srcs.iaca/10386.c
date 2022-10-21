#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *x, int index, float *delta, int scale, int n, float *truth,
    int stride)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      delta[index + i * stride] = scale * (truth[i] - x[index + i * stride]);
     } IACA_END
}

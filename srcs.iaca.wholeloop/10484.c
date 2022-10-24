#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *x, int i, int index, float *delta, int scale, int n, float *truth,
    int stride)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      delta[index + i * stride] = scale * (truth[i] - x[index + i * stride]);
     } IACA_END
}

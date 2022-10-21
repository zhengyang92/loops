#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float sigma, float *a, int n, float mu)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      a[i] = (a[i] - mu) / sigma;
     } IACA_END
}

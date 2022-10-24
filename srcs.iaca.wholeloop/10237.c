#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float sigma, float *a, int n, float mu)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      a[i] = (a[i] - mu) / sigma;
     } IACA_END
}

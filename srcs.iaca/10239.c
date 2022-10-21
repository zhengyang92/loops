#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *a, int n, float sum, int i)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      sum += a[i] * a[i];
     } IACA_END
}

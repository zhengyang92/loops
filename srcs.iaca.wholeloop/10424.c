#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int n, float sum, float *x)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      sum += fabs (x[i]);
     } IACA_END
}

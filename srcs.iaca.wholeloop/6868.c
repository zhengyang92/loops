#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float (*x)[2], int i, float sum0, int n)
{
  float sum1 = 0.0f;
  IACA_START for (i = 0; i < n; i += 2)
    {
      sum0 += x[i + 0][0] * x[i + 0][0];
      sum1 += x[i + 0][1] * x[i + 0][1];
      sum0 += x[i + 1][0] * x[i + 1][0];
      sum1 += x[i + 1][1] * x[i + 1][1];
     } IACA_END
}

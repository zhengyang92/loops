#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float e[2], int i, const float *X, const float *Y, int N)
{
  for (i = 0; i < N; i++)
     { IACA_START
      e[0] += X[i] * X[i];
      e[1] += Y[i] * Y[i];
     } IACA_END
}

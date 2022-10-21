#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *X, int i, float xp, float side, int N, float *Y)
{
  for (i = 0; i < N; i++)
     { IACA_START
      xp += X[i] * Y[i];
      side += Y[i] * Y[i];
     } IACA_END
}

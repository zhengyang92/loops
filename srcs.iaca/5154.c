#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float e[2], const float *X, const float *Y, int N)
{
  for (i = 0; i < N; i++)
    {
      e[0] += X[i] * X[i];
      e[1] += Y[i] * Y[i];
    }
}

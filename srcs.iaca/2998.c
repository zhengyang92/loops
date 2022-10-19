#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float e[2], int i, const float *X, const float *Y, int N)
{
  for (i = 0; i < N; i++)
    {
      e[0] += (X[i] + Y[i]) * (X[i] + Y[i]);
      e[1] += (X[i] - Y[i]) * (X[i] - Y[i]);
    }
}

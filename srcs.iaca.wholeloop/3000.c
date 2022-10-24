#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *X, int N, int i, float *Y)
{
  IACA_START for (i = 0; i < N; i++)
    {
      const float Xret = X[i];
      X[i] = (X[i] + Y[i]) * 0.70710678118654752440;
      Y[i] = (Y[i] - Xret) * 0.70710678118654752440;
}IACA_END}

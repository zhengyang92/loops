#include <stdint.h>
#include <stdio.h>






int
fn (float *X, int i, int *y, int N, int K, float res)
{
  int y_norm = 0;
  float xy_norm = 0.0f;
  for (i = 0; i < N; i++)
    {
      y[i] = lrintf (res * X[i]);
      y_norm += y[i] * y[i];
      xy_norm += y[i] * X[i];
      K -= ((y[i]) >= 0 ? (y[i]) : (-(y[i])));
    }
}

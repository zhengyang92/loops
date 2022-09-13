#include <stdint.h>
#include <stdio.h>






int
fn (float *pred, int i, float *delta, int n, float *truth, float *error)
{
  for (i = 0; i < n; ++i)
    {
      float diff = truth[i] - pred[i];
      error[i] = diff * diff;
      delta[i] = diff;
}}

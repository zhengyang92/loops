#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *pred, int i, float *delta, int n, float *truth, float *error)
{
  for (i = 0; i < n; ++i)
    {
      float t = truth[i];
      float p = pred[i];
      error[i] = -t * log (p) - (1 - t) * log (1 - p);
      delta[i] = t - p;
}}

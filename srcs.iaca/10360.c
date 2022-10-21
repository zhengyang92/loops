#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *pred, int i, float *delta, int n, float *truth, float *error)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      float diff = truth[i] - pred[i];
      error[i] = fabs (diff);
      delta[i] = diff > 0 ? 1 : -1;
} IACA_END }

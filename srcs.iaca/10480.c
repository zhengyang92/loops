#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, int i, float *x, float *mean, float *variance, int b, int f,
    int filters)
{
  for (i = 0; i < spatial; ++i)
     { IACA_START
      int index = b * filters * spatial + f * spatial + i;
      x[index] = (x[index] - mean[f]) / (sqrt (variance[f]) + .000001f);
} IACA_END }

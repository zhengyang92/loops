#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, int j, float *x, int i, float *mean, int k, float *variance,
    int filters)
{
  for (k = 0; k < spatial; ++k)
    {
      int index = j * filters * spatial + i * spatial + k;
      variance[i] += pow ((x[index] - mean[i]), 2);
}}

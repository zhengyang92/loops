#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, int j, int i, float *x, float *mean, int k, int filters)
{
  for (k = 0; k < spatial; ++k)
    {
      int index = j * filters * spatial + i * spatial + k;
      mean[i] += x[index];
}}

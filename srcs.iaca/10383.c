#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, int j, int i, float *mean_delta, int k, float *delta,
    int filters)
{
  for (k = 0; k < spatial; ++k)
    {
      int index = j * filters * spatial + i * spatial + k;
      mean_delta[i] += delta[index];
}}

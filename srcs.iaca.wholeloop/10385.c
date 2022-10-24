#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, int j, float *x, float *mean_delta, float *mean, int batch,
    int k, float *delta, float *variance, int f, int filters,
    float *variance_delta)
{
  IACA_START for (k = 0; k < spatial; ++k)
    {
      int index = j * filters * spatial + f * spatial + k;
      delta[index] =
	delta[index] * 1. / (sqrt (variance[f] + .00001f)) +
	variance_delta[f] * 2. * (x[index] - mean[f]) / (spatial * batch) +
	mean_delta[f] / (spatial * batch);
}IACA_END}

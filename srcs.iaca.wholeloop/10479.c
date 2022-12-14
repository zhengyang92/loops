#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, float *x, int i, float *dx, int b, int f, float sum,
    int filters)
{
  IACA_START for (f = 0; f < filters; ++f)
    {
      int index = b * filters * spatial + f * spatial + i;
      x[index] /= sum;
      dx[index] = (1 - x[index]) / sum;
}IACA_END}

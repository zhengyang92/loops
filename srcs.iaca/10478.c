#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, float *x, int i, int b, int f, float sum, int filters)
{
  for (f = 0; f < filters; ++f)
     { IACA_START
      int index = b * filters * spatial + f * spatial + i;
      sum += powf (x[index], 2);
} IACA_END }

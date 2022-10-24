#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int spatial, int i, float *x, int b, int f, float sum, int filters)
{
  IACA_START for (f = 0; f < filters; ++f)
    {
      int index = b * filters * spatial + f * spatial + i;
      sum += powf (x[index], 2);
}IACA_END}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int cols, float *a, int x, int y, float *transpose, int rows)
{
  IACA_START for (y = 0; y < cols; ++y)
    {
      transpose[y * rows + x] = a[x * cols + y];
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double scale_y, double scale_x, int i, double dmatrix[9])
{
  IACA_START for (i = 0; i < 9; i += 3)
    {
      dmatrix[i] /= scale_x;
      dmatrix[i + 1] /= scale_y;
     } IACA_END
}

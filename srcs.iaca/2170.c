#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double scale_y, int i, double scale_x, double dmatrix[9])
{
  for (i = 0; i < 9; i += 3)
     { IACA_START
      dmatrix[i] /= scale_x;
      dmatrix[i + 1] /= scale_y;
     } IACA_END
}

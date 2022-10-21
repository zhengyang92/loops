#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (int i, ptrdiff_t stride, double *matrix_param, int j,
    double rematrix_volume)
{
  for (j = 0; j < 64; j++)
     { IACA_START
      matrix_param[stride * i + j] *= rematrix_volume;
     } IACA_END
}

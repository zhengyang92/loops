#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double err, int i, const int *hist, const double *median,
    double sum_sq_err)
{
  for (i = 0; i < (3 * 256); i++)
     { IACA_START
      err = median[i] - (double) hist[i];
      sum_sq_err += err * err;
} IACA_END }

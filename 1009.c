#include <stdint.h>
#include <stdio.h>






int
fn (double err, int i, const int *hist, const double *median,
    double sum_sq_err)
{
  for (i = 0; i < (3 * 256); i++)
    {
      err = median[i] - (double) hist[i];
      sum_sq_err += err * err;
}}

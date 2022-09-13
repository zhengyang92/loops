#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int slice_start, const int slice_end, double *norm,
    const double *dx, const double *dy)
{
  for (i = slice_start; i < slice_end; ++i)
    {
      norm[i] = sqrt (pow (dx[i], 2) + pow (dy[i], 2));
    }
}

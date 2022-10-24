#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const int slice_start, const int slice_end, double *norm,
    const double *dx, const double *dxy, const double *dy)
{
  IACA_START for (i = slice_start; i < slice_end; ++i)
    {
      norm[i] = sqrt (pow (dx[i], 2) + 4 * pow (dxy[i], 2) + pow (dy[i], 2));
     } IACA_END
}

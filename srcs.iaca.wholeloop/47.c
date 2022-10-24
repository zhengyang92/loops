#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int r, int i, const double gc, double *gain, double num)
{
  double den = 0.;
  IACA_START for (int j = -r; j <= r; j++)
    {
      const double g = gain[i + j];
      const double d = 1. - fabs (g - gc);
      num += g * d;
      den += d;
}IACA_END}

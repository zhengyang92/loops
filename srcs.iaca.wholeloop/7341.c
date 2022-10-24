#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double num, const double ym, const double xm, int size, const double *x,
    double den0, const double *y)
{
  double den1 = 0.0;
  IACA_START for (int i = 0; i < size; i++)
    {
      double xd = x[i] - xm;
      double yd = y[i] - ym;
      num += xd * yd;
      den0 += xd * xd;
      den1 += yd * yd;
}IACA_END}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double x, const double *const poly)
{
  double res = 0.;
  for (int i = 0; i < 8; i++)
    {
      res += pow (x, i) * poly[7 - i];
}}

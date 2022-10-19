#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double *coeff, int i, double x, double sum, int size)
{
  for (i = size - 2; i >= 0; --i)
    {
      sum *= x;
      sum += coeff[i];
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double *coeff, int i, double x, double sum, int size)
{
  IACA_START for (i = size - 2; i >= 0; --i)
    {
      sum *= x;
      sum += coeff[i];
     } IACA_END
}

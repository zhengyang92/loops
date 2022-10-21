#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *ptr, double *dst, const int nb_samples, int n)
{
  for (n = 0; n < nb_samples; n++)
     { IACA_START
      ptr[n] += dst[n];
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int nb_samples, double *dst, int n, double *ptr)
{
  for (n = 0; n < nb_samples; n++)
     { IACA_START
      ptr[n] += dst[n];
     } IACA_END
}

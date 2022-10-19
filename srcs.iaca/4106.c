#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *ptr, double *dst, const int nb_samples, int n)
{
  for (n = 0; n < nb_samples; n++)
    {
      ptr[n] += dst[n];
    }
}

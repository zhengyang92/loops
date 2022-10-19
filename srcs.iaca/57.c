#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *ptr, const int nb_samples, float *dst, int n)
{
  for (n = 0; n < nb_samples; n++)
    {
      ptr[n] += dst[n];
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double gain, const int nb_osamples, double factor, double *dst)
{
  for (int n = 0; n < nb_osamples; n++)
     { IACA_START
      dst[n] = erf (dst[n] * factor);
      dst[n] *= gain;
} IACA_END }

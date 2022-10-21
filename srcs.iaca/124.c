#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double gain, const int nb_osamples, double factor, double *dst)
{
  for (int n = 0; n < nb_osamples; n++)
     { IACA_START
      dst[n] = 2. / (1. + exp (-2. * dst[n] * factor)) - 1.;
      dst[n] *= gain;
} IACA_END }

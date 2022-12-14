#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double gain, const int nb_osamples, double factor, double *dst)
{
  IACA_START for (int n = 0; n < nb_osamples; n++)
    {
      dst[n] = 2. / (1. + exp (-2. * dst[n] * factor)) - 1.;
      dst[n] *= gain;
}IACA_END}

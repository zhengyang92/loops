#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double gain, double param, double factor, const int nb_osamples,
    double *dst)
{
  for (int n = 0; n < nb_osamples; n++)
     { IACA_START
      dst[n] = 2. / 3.14159265358979323846 * atan (dst[n] * factor * param);
      dst[n] *= gain;
} IACA_END }

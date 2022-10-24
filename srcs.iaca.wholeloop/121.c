#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double gain, double param, double factor, const int nb_osamples,
    double *dst)
{
  IACA_START for (int n = 0; n < nb_osamples; n++)
    {
      dst[n] = tanh (dst[n] * factor * param);
      dst[n] *= gain;
}IACA_END}

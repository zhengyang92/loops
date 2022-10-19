#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double gain, double param, double factor, const int nb_osamples,
    double *dst)
{
  for (int n = 0; n < nb_osamples; n++)
    {
      double sample = dst[n] * factor;
      dst[n] = sample / (sqrt (param + sample * sample));
      dst[n] *= gain;
}}

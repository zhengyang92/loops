#include <stdint.h>
#include <stdio.h>






int
fn (float factor, float *dst, float gain, const int nb_osamples)
{
  for (int n = 0; n < nb_osamples; n++)
    {
      dst[n] = 2.f / (1.f + expf (-2.f * dst[n] * factor)) - 1.;
      dst[n] *= gain;
}}

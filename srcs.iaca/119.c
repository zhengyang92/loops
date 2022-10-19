#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float gain, float *dst, float factor, const int nb_osamples)
{
  for (int n = 0; n < nb_osamples; n++)
    {
      dst[n] = erff (dst[n] * factor);
      dst[n] *= gain;
}}

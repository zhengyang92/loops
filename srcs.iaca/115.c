#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float gain, float *dst, float factor, const int nb_osamples)
{
  for (int n = 0; n < nb_osamples; n++)
     { IACA_START
      dst[n] = 2.f / (1.f + expf (-2.f * dst[n] * factor)) - 1.;
      dst[n] *= gain;
} IACA_END }

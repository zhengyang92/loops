#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float factor, float gain, float *dst, const int nb_osamples, float param)
{
  for (int n = 0; n < nb_osamples; n++)
     { IACA_START
      float sample = dst[n] * factor;
      dst[n] = sample / (sqrtf (param + sample * sample));
      dst[n] *= gain;
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double gain, const int nb_osamples, double factor, double *dst)
{
  for (int n = 0; n < nb_osamples; n++)
     { IACA_START
      dst[n] = av_clipd_sse2 (dst[n] * factor, -1., 1.);
      dst[n] *= gain;
} IACA_END }

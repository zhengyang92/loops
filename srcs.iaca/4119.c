#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float factor, float *dst, float gain, const int nb_osamples)
{
  for (int n = 0; n < nb_osamples; n++)
     { IACA_START
      dst[n] = av_clipf_sse (dst[n] * factor, -1.f, 1.f);
      dst[n] *= gain;
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int nb_osamples, float factor, float *dst, float gain)
{
  IACA_START for (int n = 0; n < nb_osamples; n++)
    {
      dst[n] = 2.f / (1.f + expf (-2.f * dst[n] * factor)) - 1.;
      dst[n] *= gain;
}IACA_END}

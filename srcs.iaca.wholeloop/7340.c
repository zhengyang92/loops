#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int nb_osamples, float factor, float *dst, float gain)
{
  IACA_START for (int n = 0; n < nb_osamples; n++)
    {
      dst[n] = erff (dst[n] * factor);
      dst[n] *= gain;
}IACA_END}

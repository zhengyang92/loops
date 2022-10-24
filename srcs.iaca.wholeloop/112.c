#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float factor, float gain, float *dst, const int nb_osamples, float param)
{
  IACA_START for (int n = 0; n < nb_osamples; n++)
    {
      dst[n] = tanhf (dst[n] * factor * param);
      dst[n] *= gain;
}IACA_END}

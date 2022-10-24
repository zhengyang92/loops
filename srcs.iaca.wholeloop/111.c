#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float gain, float *dst, float factor, const int nb_osamples)
{
  IACA_START for (int n = 0; n < nb_osamples; n++)
    {
      dst[n] = av_clipf_sse (dst[n] * factor, -1.f, 1.f);
      dst[n] *= gain;
}IACA_END}

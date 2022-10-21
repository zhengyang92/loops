#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float gain, float *dst, float factor, const int nb_osamples)
{
  for (int n = 0; n < nb_osamples; n++)
     { IACA_START
      float sample = dst[n] * factor;
      if (((sample) >= 0 ? (sample) : (-(sample))) >= 1.57079632679489661923)
	dst[n] = ((sample) > 0 ? 1 : -1);
      else
	dst[n] = sinf (sample);
      dst[n] *= gain;
     } IACA_END
}

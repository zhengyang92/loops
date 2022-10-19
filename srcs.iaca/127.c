#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double gain, const int nb_osamples, double factor, double *dst)
{
  for (int n = 0; n < nb_osamples; n++)
    {
      double sample = dst[n] * factor;
      if (((sample) >= 0 ? (sample) : (-(sample))) >= 1.57079632679489661923)
	dst[n] = ((sample) > 0 ? 1 : -1);
      else
	dst[n] = sin (sample);
      dst[n] *= gain;
    }
}

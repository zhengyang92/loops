#include <stdint.h>
#include <stdio.h>






int
fn (double gain, const int nb_osamples, double factor, double *dst)
{
  for (int n = 0; n < nb_osamples; n++)
    {
      double sample = dst[n] * factor;
      if (((sample) >= 0 ? (sample) : (-(sample))) >= 1.5)
	dst[n] = ((sample) > 0 ? 1 : -1);
      else
	dst[n] = sample - 0.1481 * pow (sample, 3.);
      dst[n] *= gain;
    }
}

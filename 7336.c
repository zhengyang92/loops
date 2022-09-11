#include <stdint.h>
#include <stdio.h>






int
fn (const int nb_osamples, float factor, float *dst, float gain)
{
  for (int n = 0; n < nb_osamples; n++)
    {
      float sample = dst[n] * factor;
      if (((sample) >= 0 ? (sample) : (-(sample))) >= 1.5f)
	dst[n] = ((sample) > 0 ? 1 : -1);
      else
	dst[n] = sample - 0.1481f * powf (sample, 3.f);
      dst[n] *= gain;
    }
}

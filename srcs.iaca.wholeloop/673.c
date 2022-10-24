#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int nb_match_blocks, const float sigma_sqr, int k, float *bufferz,
    float *rbufferz, float l2_wiener)
{
  IACA_START for (k = 0; k < nb_match_blocks; k++)
    {
      const float ref_sqr = rbufferz[k] * rbufferz[k];
      float wiener_coef = ref_sqr / (ref_sqr + sigma_sqr);
      if (__builtin_isnan (wiener_coef))
	wiener_coef = 1;
      bufferz[k] *= wiener_coef;
      l2_wiener += wiener_coef * wiener_coef;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int ncoeffs, int32_t * lfe_samples, float b, const float *filter_coeff,
    int k, float a, int j)
{
  for (k = 0; k < ncoeffs; k++)
     { IACA_START
      a += filter_coeff[j * ncoeffs + k] * lfe_samples[-k];
      b += filter_coeff[255 - j * ncoeffs - k] * lfe_samples[-k];
     } IACA_END
}

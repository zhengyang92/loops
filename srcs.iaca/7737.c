#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int32_t int32_t;

int
fn (const int32_t * filter_coeff, int32_t * lfe_samples, int64_t a, int64_t b,
    int k, int j)
{
  for (k = 0; k < 8; k++)
     { IACA_START
      a += (int64_t) filter_coeff[j * 8 + k] * lfe_samples[-k];
      b += (int64_t) filter_coeff[255 - j * 8 - k] * lfe_samples[-k];
     } IACA_END
}

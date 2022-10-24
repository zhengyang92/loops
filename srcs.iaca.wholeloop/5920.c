#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *coefs, float v1, int j, const float *in, int num_coeffs,
    float v0)
{
  IACA_START for (j = 0; j < num_coeffs; j++, coefs++)
    {
      v0 += in[-j] * *coefs;
      v1 += in[j + 1 - num_coeffs] * *coefs;
     } IACA_END
}

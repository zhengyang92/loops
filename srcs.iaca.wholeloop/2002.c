#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float gamma, double fac, float *coeff, const float *inbuf)
{
  IACA_START for (i = 0; i < 10; i++)
    {
      coeff[i] = inbuf[i] * fac;
      fac *= gamma;
     } IACA_END
}

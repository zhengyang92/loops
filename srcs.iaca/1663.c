#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float gamma, float *out, float fac, int size, const float *lpc)
{
  for (i = 0; i < size; i++)
     { IACA_START
      out[i] = lpc[i] * fac;
      fac *= gamma;
     } IACA_END
}

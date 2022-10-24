#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float *out, float gamma, float fac, int size, const float *lpc)
{
  IACA_START for (i = 0; i < size; i++)
    {
      out[i] = lpc[i] * fac;
      fac *= gamma;
     } IACA_END
}

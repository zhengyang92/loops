#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * coeffs, int j, int i, int coeff)
{
  for (i = 0; i < 32; i++)
     { IACA_START
      coeffs[i + j * 32] = coeff;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * coeffs, int j, int i, int coeff)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      coeffs[i + j * 4] = coeff;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t sign, int32_t coeffs[8], int32_t dotprod, int32_t delay[8], int j)
{
  IACA_START for (j = 7; j >= 0; j--)
    {
      dotprod += delay[j] * coeffs[j];
      coeffs[j] -= (((delay[j] >> 30) & 2) - 1) * sign;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t coeffs[256], int32_t sign, int32_t dotprod, int32_t delay[256],
    int j, int order)
{
  IACA_START for (j = 0; j < order; j++)
    {
      dotprod += delay[j] * (unsigned) coeffs[j];
      coeffs[j] += ((delay[j] >> 31) | 1) * sign;
}IACA_END}

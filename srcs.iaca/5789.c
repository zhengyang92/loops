#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t sign, int32_t dotprod, int order, int j, int32_t * coeffs,
    int32_t * delay)
{
  for (j = 0; j < order; j++)
    {
      dotprod += delay[j] * coeffs[j];
      coeffs[j] -= (((delay[j] >> 30) & 2) - 1) * sign;
    }
}

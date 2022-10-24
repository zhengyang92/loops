#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (unsigned int a1, int length, int32_t * coeffs, int i)
{
  IACA_START for (i = 0; i < length - 1 >> 1; i++)
    {
      *coeffs += a1;
      coeffs[1] += (unsigned) *coeffs;
      a1 = coeffs[1];
      coeffs += 2;
}IACA_END}

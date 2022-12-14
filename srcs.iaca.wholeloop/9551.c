#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int a1, int i, int a2, int length, int32_t * coeffs)
{
  IACA_START for (i = 0; i < length - 2 >> 1; i++)
    {
      int a3 = *coeffs + a1;
      int a4 = a3 + a2;
      *coeffs = a4;
      a1 = coeffs[1] + a3;
      a2 = a1 + a4;
      coeffs[1] = a2;
      coeffs += 2;
}IACA_END}

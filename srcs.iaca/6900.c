#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int length, int a1, int32_t * coeffs, int i)
{
  for (i = 0; i < length - 1 >> 1; i++)
     { IACA_START
      *coeffs += a1;
      coeffs[1] += *coeffs;
      a1 = coeffs[1];
      coeffs += 2;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int32_t tmp, int16_t * a, int i, int32_t f[2][6])
{
  IACA_START for (i = 5; i > 0; i--)
    {
      tmp = f[0][6 - i] + (unsigned) f[1][6 - i] + 4096;
      a[6 - i] = tmp >> 13;
      tmp = f[0][6 - i] - (unsigned) f[1][6 - i] + 4096;
      a[5 + i] = tmp >> 13;
}IACA_END}

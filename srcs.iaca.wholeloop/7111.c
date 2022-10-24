#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int64_t x86_reg;
typedef __int16_t int16_t;

int
fn (int scale, x86_reg i, int16_t * rem, int16_t * basis)
{
  IACA_START for (i = 0; i < 8 * 8; i++)
    {
      rem[i] += (basis[i] * scale + (1 << (16 - 6 - 1))) >> (16 - 6);
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t q[9], int order, int k, int32_t p[9], int32_t lpc32[16])
{
  IACA_START for (k = 0; k < order >> 1; k++)
    {
      lpc32[k] = -p[k + 1] - p[k] - q[k + 1] + q[k];
      lpc32[order - k - 1] = -p[k + 1] - p[k] + q[k + 1] - q[k];
     } IACA_END
}

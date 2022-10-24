#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float ff_pow_0_5[16], int i, const float ff_pow_0_75[10],
    float lpc_d[10], float lpc_n[10], const float *lpc)
{
  IACA_START for (i = 0; i < 10; i++)
    {
      lpc_d[i] = lpc[i] * ff_pow_0_75[i];
      lpc_n[i] = lpc[i] * ff_pow_0_5[i];
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float lpc_d[10], const float *gamma_d, const float *gamma_n,
    float lpc_n[10], float *lpc)
{
  for (i = 0; i < 10; i++)
     { IACA_START
      lpc_n[i] = lpc[i] * gamma_n[i];
      lpc_d[i] = lpc[i] * gamma_d[i];
     } IACA_END
}

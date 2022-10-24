#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t * chrFilter, int i, const int16_t ** chrVSrc, int v, int u,
    const int16_t ** chrUSrc, int j, int chrFilterSize)
{
  IACA_START for (j = 0; j < chrFilterSize; j++)
    {
      u += chrUSrc[j][i] * chrFilter[j];
      v += chrVSrc[j][i] * chrFilter[j];
     } IACA_END
}

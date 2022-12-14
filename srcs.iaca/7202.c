#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (const int32_t ** chrUSrc, const int16_t * chrFilter, int i,
    const int32_t ** chrVSrc, int U, int j, int chrFilterSize, int V)
{
  for (j = 0; j < chrFilterSize; j++)
     { IACA_START
      U += chrUSrc[j][i] * chrFilter[j];
      V += chrVSrc[j][i] * chrFilter[j];
     } IACA_END
}

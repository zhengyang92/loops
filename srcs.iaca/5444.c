#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (const int32_t ** uSrc, const int16_t * chrFilter, int i,
    const int32_t ** vSrc, int v, int u, int j, int chrFilterSize)
{
  for (j = 0; j < chrFilterSize; j++)
     { IACA_START
      u += uSrc[j][i] * (unsigned) chrFilter[j];
      v += vSrc[j][i] * (unsigned) chrFilter[j];
} IACA_END }

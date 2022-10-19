#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t * chrFilter, int i, const int16_t ** chrVSrc,
    const int16_t ** chrUSrc, int U, int j, int chrFilterSize, int V)
{
  for (j = 0; j < chrFilterSize; j++)
    {
      U += chrUSrc[j][i] * chrFilter[j];
      V += chrVSrc[j][i] * chrFilter[j];
    }
}

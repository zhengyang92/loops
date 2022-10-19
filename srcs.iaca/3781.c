#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (const int16_t * chrFilter, const int32_t ** chrUSrc, int i,
    const int32_t ** chrVSrc, int U, int j, int chrFilterSize, int V)
{
  for (j = 0; j < chrFilterSize; j++)
    {;
      U += chrUSrc[j][i] * (unsigned) chrFilter[j];
      V += chrVSrc[j][i] * (unsigned) chrFilter[j];
}}

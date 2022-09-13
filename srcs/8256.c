#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (const int32_t ** chrUSrc, const int16_t * chrFilter, int i,
    const int32_t ** chrVSrc, int U, int j, int chrFilterSize, int V)
{
  for (j = 0; j < chrFilterSize; j++)
    {
      U += chrUSrc[j][i] * (unsigned) chrFilter[j];
      V += chrVSrc[j][i] * (unsigned) chrFilter[j];
}}

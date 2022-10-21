#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int i, const int16_t * lumFilter, int lumFilterSize, int Y1, int j,
    const int32_t ** lumSrc, int Y2)
{
  for (j = 0; j < lumFilterSize; j++)
     { IACA_START
      Y1 += lumSrc[j][i * 2] * (unsigned) lumFilter[j];
      Y2 += lumSrc[j][i * 2 + 1] * (unsigned) lumFilter[j];
} IACA_END }

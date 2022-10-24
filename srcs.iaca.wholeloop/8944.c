#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int i, const int16_t * lumFilter, int j, int Y1, int lumFilterSize,
    const int32_t ** lumSrc, int Y2)
{
  IACA_START for (j = 0; j < lumFilterSize; j++)
    {
      Y1 += lumSrc[j][i * 2] * (unsigned) lumFilter[j];
      Y2 += lumSrc[j][i * 2 + 1] * (unsigned) lumFilter[j];
}IACA_END}

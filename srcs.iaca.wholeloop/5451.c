#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int Y, int i, int lumFilterSize, int j, const int32_t ** lumSrc,
    const int16_t * lumFilter)
{
  IACA_START for (j = 0; j < lumFilterSize; j++)
    {
      Y += lumSrc[j][i] * (unsigned) lumFilter[j];
}IACA_END}

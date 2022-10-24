#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** lumSrc, int Y2, int i, int lumFilterSize, int Y1, int j,
    const int16_t * lumFilter)
{
  IACA_START for (j = 0; j < lumFilterSize; j++)
    {
      Y1 += lumSrc[j][i] * lumFilter[j];
      Y2 += lumSrc[j][i + 1] * lumFilter[j];
     } IACA_END
}

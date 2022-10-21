#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** lumSrc, int Y2, int i, int j, int Y1, int lumFilterSize,
    const int16_t * lumFilter)
{
  for (j = 0; j < lumFilterSize; j++)
     { IACA_START
      Y1 += lumSrc[j][i * 2] * lumFilter[j];
      Y2 += lumSrc[j][i * 2 + 1] * lumFilter[j];
     } IACA_END
}

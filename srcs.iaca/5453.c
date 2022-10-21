#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** lumSrc, int i, const int16_t * lumFilter, int j, int Y1,
    int lumFilterSize, int Y2)
{
  for (j = 0; j < lumFilterSize; j++)
     { IACA_START
      Y1 += lumSrc[j][i * 2] * lumFilter[j];
      Y2 += lumSrc[j][i * 2 + 1] * lumFilter[j];
     } IACA_END
}

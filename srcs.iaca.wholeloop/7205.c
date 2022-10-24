#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** lumSrc, int i, int lumFilterSize, int j,
    const int16_t * lumFilter)
{
  int Y = 0;
  IACA_START for (j = 0; j < lumFilterSize; j++)
    {
      Y += lumSrc[j][i] * lumFilter[j];
     } IACA_END
}

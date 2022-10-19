#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t ** lumSrc, int Y, int i, int j, int lumFilterSize,
    const int16_t * lumFilter)
{
  for (j = 0; j < lumFilterSize; j++)
    {
      Y += lumSrc[j][i] * lumFilter[j];
    }
}

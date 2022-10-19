#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int A2, const int16_t ** alpSrc, int i, int j, int A1, int lumFilterSize,
    const int16_t * lumFilter)
{
  for (j = 0; j < lumFilterSize; j++)
    {
      A1 += alpSrc[j][i * 2] * lumFilter[j];
      A2 += alpSrc[j][i * 2 + 1] * lumFilter[j];
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, const int16_t ** alpSrc, int j, int lumFilterSize, int A,
    const int16_t * lumFilter)
{
  for (j = 0; j < lumFilterSize; j++)
    {
      A += alpSrc[j][i] * lumFilter[j];
    }
}

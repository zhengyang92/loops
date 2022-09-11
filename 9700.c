#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int Y2, int i, int lumFilterSize, int Y1, int j, const int32_t ** lumSrc,
    const int16_t * lumFilter)
{
  for (j = 0; j < lumFilterSize; j++)
    {
      Y1 += lumSrc[j][i * 2] * lumFilter[j];
      Y2 += lumSrc[j][i * 2 + 1] * lumFilter[j];
    }
}

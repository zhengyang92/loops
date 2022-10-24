#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int i, const int16_t * filter, int filterSize, const uint8_t * src, int j,
    int srcPos)
{
  int val = 0;
  IACA_START for (j = 0; j < filterSize; j++)
    {
      val += ((int) src[srcPos + j]) * filter[filterSize * i + j];
}IACA_END}

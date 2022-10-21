#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int i, const int16_t * filter, int filterSize, const uint8_t * src, int j,
    int srcPos)
{
  int val = 0;
  for (j = 0; j < filterSize; j++)
     { IACA_START
      val += ((int) src[srcPos + j]) * filter[filterSize * i + j];
} IACA_END }

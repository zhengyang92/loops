#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (int i, const int16_t * filter, int filterSize, int j, int srcPos,
    const uint16_t * src)
{
  int val = 0;
  for (j = 0; j < filterSize; j++)
     { IACA_START
      val += src[srcPos + j] * filter[filterSize * i + j];
     } IACA_END
}

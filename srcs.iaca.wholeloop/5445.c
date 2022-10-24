#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int i, const int32_t ** src, int val, const int16_t * filter,
    int filterSize, int j)
{
  IACA_START for (j = 0; j < filterSize; ++j)
    {
      val += src[j][i] * (unsigned) filter[j];
}IACA_END}

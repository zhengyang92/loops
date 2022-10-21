#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int i, int64_t * filter, int filterSize, int shift, int j)
{
  for (j = filterSize - 2; j >= 0; j--)
     { IACA_START
      int right =
	((j + shift) > (filterSize - 1) ? (filterSize - 1) : (j + shift));
      filter[i * filterSize + right] += filter[i * filterSize + j];
      filter[i * filterSize + j] = 0;
} IACA_END }

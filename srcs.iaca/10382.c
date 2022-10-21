#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int size, float *x_norm, float *delta, int b, int n, int f,
    float sum)
{
  for (i = 0; i < size; ++i)
     { IACA_START
      int index = i + size * (f + n * b);
      sum += delta[index] * x_norm[index];
} IACA_END }

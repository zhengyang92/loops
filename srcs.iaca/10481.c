#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *input, float largest, float sum, int i, float *output, float temp,
    int n, int stride)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      float e = exp (input[i * stride] / temp - largest / temp);
      sum += e;
      output[i * stride] = e;
} IACA_END }

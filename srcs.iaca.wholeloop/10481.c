#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *input, float largest, float sum, int i, float *output, float temp,
    int n, int stride)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      float e = exp (input[i * stride] / temp - largest / temp);
      sum += e;
      output[i * stride] = e;
}IACA_END}

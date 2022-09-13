#include <stdint.h>
#include <stdio.h>






int
fn (float *input, float largest, int i, float temp, float *output, int n,
    int stride, float sum)
{
  for (i = 0; i < n; ++i)
    {
      float e = exp (input[i * stride] / temp - largest / temp);
      sum += e;
      output[i * stride] = e;
}}

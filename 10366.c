#include <stdint.h>
#include <stdio.h>






int
fn (int i, float sum, float *output, int n, int stride)
{
  for (i = 0; i < n; ++i)
    {
      output[i * stride] /= sum;
    }
}

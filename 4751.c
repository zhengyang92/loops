#include <stdint.h>
#include <stdio.h>






int
fn (int i, float sum2, float *in, float scratch[54], int length, float sum1)
{
  for (i = 0, sum1 = 0, sum2 = 0; i < length; i++)
    {
      sum1 += in[i] * in[i];
      sum2 += scratch[i] * scratch[i];
    }
}

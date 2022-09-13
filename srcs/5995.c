#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int i, int16_t ** samples, int len, int32_t ** in, int shift)
{
  for (i = 0; i < len; i++)
    {
      int a = in[0][i];
      int b = in[1][i];
      a -= b >> 1;
      (samples[0][i]) = (a + b) << shift;
      (samples[1][i]) = a << shift;
}}

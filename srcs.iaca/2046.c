#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int i, int len, int16_t ** samples, int32_t ** in, int shift)
{
  for (i = 0; i < len; i++)
    {
      unsigned a = in[0][i];
      unsigned b = in[1][i];
      (samples[0][i]) = a << shift;
      (samples[1][i]) = (a - b) << shift;
}}

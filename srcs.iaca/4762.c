#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;
typedef __int16_t int16_t;

int
fn (int i, int len, int16_t ** samples, int32_t ** in, int shift)
{
  for (i = 0; i < len; i++)
     { IACA_START
      unsigned a = in[0][i];
      unsigned b = in[1][i];
      (samples[0][i]) = (a + b) << shift;
      (samples[1][i]) = b << shift;
} IACA_END }

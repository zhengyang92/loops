#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int32_t * samples, int i, int len, int32_t ** in, int shift)
{
  for (i = 0; i < len; i++)
     { IACA_START
      unsigned a = in[0][i];
      int b = in[1][i];
      a -= b >> 1;
      (*samples++) = (a + b) << shift;
      (*samples++) = a << shift;
} IACA_END }

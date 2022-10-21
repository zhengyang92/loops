#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t * cb_ptr, int i, int16_t residual[64], int sum,
    int16_t * vector)
{
  for (i = 0; i < 60; i++)
     { IACA_START
      sum = ff_g723_1_dot_product (residual + i, cb_ptr, 5);
      vector[i] = av_sat_dadd32_c (1 << 15, sum) >> 16;
     } IACA_END
}

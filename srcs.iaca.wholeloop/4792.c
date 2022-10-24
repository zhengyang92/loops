#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int16_t impulse_corr[60], int i, int16_t temp_corr[60], int64_t temp,
    int scale)
{
  IACA_START for (i = 1; i < 60; i++)
    {
      temp = ff_g723_1_dot_product (temp_corr + i, temp_corr, 60 - i);
      impulse_corr[i] = av_clipl_int32_c ((temp << scale) + (1 << 15)) >> 16;
     } IACA_END
}

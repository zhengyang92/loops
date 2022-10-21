#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int ccr1[60], int16_t impulse_r[60], int i, int16_t * buf, int64_t temp,
    int scale)
{
  for (i = 0; i < 60; i++)
     { IACA_START
      temp = ff_g723_1_dot_product (buf + i, impulse_r, 60 - i);
      if (scale < 0)
	ccr1[i] = temp >> -scale;
      else
	ccr1[i] = av_clipl_int32_c (temp << scale);
     } IACA_END
}

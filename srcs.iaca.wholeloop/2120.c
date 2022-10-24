#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int ccr_buf[80], int16_t flt_buf[5][60], int64_t temp,
    const int16_t * buf, int j)
{
  int count = 0;
  IACA_START for (j = 0; j < 5; j++)
    {
      temp = ff_dot_product (buf, flt_buf[j], 60);
      ccr_buf[count++] = av_clipl_int32_c (temp << 1);
     } IACA_END
}

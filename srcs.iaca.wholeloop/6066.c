#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (int16_t flt_buf[5][60], int64_t temp, int k, int ccr_buf[80], int j)
{
  int count = 0;
  IACA_START for (k = 0; k < j; k++)
    {
      temp = ff_dot_product (flt_buf[j], flt_buf[k], 60);
      ccr_buf[count++] = av_clipl_int32_c (temp << 2);
     } IACA_END
}

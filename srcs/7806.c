#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (const int16_t * buf, int16_t flt_buf[5][60], int64_t temp,
    int ccr_buf[80], int j)
{
  int count = 0;
  for (j = 0; j < 5; j++)
    {
      temp = ff_dot_product (buf, flt_buf[j], 60);
      ccr_buf[count++] = av_clipl_int32_c (temp << 1);
    }
}

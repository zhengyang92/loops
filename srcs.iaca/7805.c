#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;
typedef __int16_t int16_t;

int
fn (int16_t * residual, int16_t flt_buf[5][60], int16_t * impulse_resp,
    int64_t temp, int k, int j)
{
  for (k = 1; k < 60; k++)
    {
      temp = (flt_buf[j + 1][k - 1] << 15) + residual[j] * impulse_resp[k];
      flt_buf[j][k] = av_clipl_int32_c ((temp << 1) + (1 << 15)) >> 16;
    }
}

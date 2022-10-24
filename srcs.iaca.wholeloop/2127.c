#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int64_t int64_t;

int
fn (int16_t impulse_r[60], int16_t temp_corr[60], int64_t temp, int k, int l)
{
  IACA_START for (l = 0; l <= k; l++)
    {
      int prod =
	av_clipl_int32_c ((int64_t) temp_corr[l] * impulse_r[k - l] << 1);
      temp = av_clipl_int32_c (temp + prod);
}IACA_END}

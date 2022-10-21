#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * buf, int16_t temp_corr[60], int err, int k)
{
  for (k = 0; k < 60; k++)
     { IACA_START
      int64_t prod;
      prod = av_clipl_int32_c ((int64_t) buf[k] * temp_corr[k] << 1);
      err = av_clipl_int32_c (err - prod);
      prod = av_clipl_int32_c ((int64_t) temp_corr[k] * temp_corr[k]);
      err = av_clipl_int32_c (err + prod);
     } IACA_END
}

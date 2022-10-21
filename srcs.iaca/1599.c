#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *coef1, int i, float *sum, int len, const float *coef0)
{
  for (i = 0; i < len; i++)
     { IACA_START
      float lt = coef0[i];
      float rt = coef1[i];
      float md = lt + rt;
      float sd = lt - rt;
      sum[0] += lt * lt;
      sum[1] += rt * rt;
      sum[2] += md * md;
      sum[3] += sd * sd;
} IACA_END }

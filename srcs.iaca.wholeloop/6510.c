#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, double error, int32_t * lpc_out, int sh, int32_t qmax, int order,
    double *lpc_in)
{
  IACA_START for (i = 0; i < order; i++)
    {
      error -= lpc_in[i] * (1 << sh);
      lpc_out[i] = av_clip_c (lrintf (error), -qmax, qmax);
      error -= lpc_out[i];
     } IACA_END
}

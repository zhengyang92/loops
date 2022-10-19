#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int opt_order, int i, int32_t coefs[32][32], int32_t qmax,
    int32_t lpc_try[32], int tmp)
{
  int diffsum = 0;
  for (i = 0; i < opt_order; i++)
    {
      int diff = ((tmp + 1) % 3) - 1;
      lpc_try[i] = av_clip_c (coefs[opt_order - 1][i] + diff, -qmax, qmax);
      tmp /= 3;
      diffsum += !!diff;
}}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVExpr;
typedef long int ptrdiff_t;

int
fn (int VAR_B, int VAR_X, const float *bottom, int x, float *dst,
    ptrdiff_t width, int VAR_TOP, int VAR_BOTTOM, AVExpr * e, double *values,
    const float *top, int VAR_A)
{
  for (x = 0; x < width; x++)
     { IACA_START
      values[VAR_X] = x;
      values[VAR_TOP] = values[VAR_A] = top[x];
      values[VAR_BOTTOM] = values[VAR_B] = bottom[x];
      dst[x] = av_expr_eval (e, values, ((void *) 0));
} IACA_END }

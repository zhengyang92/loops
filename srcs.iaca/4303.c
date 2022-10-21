#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVExpr;
typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int VAR_B, int VAR_X, const uint16_t * bottom, int x, ptrdiff_t width,
    int VAR_TOP, int VAR_BOTTOM, AVExpr * e, const uint16_t * top,
    double *values, int VAR_A, uint16_t * dst)
{
  for (x = 0; x < width; x++)
     { IACA_START
      values[VAR_X] = x;
      values[VAR_TOP] = values[VAR_A] = top[x];
      values[VAR_BOTTOM] = values[VAR_B] = bottom[x];
      dst[x] = av_expr_eval (e, values, ((void *) 0));
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef AVExpr;
typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int VAR_B, int VAR_X, int x, ptrdiff_t width, int VAR_TOP, int VAR_BOTTOM,
    uint8_t * dst, AVExpr * e, double *values, const uint8_t * top, int VAR_A,
    const uint8_t * bottom)
{
  IACA_START for (x = 0; x < width; x++)
    {
      values[VAR_X] = x;
      values[VAR_TOP] = values[VAR_A] = top[x];
      values[VAR_BOTTOM] = values[VAR_B] = bottom[x];
      dst[x] = av_expr_eval (e, values, ((void *) 0));
}IACA_END}

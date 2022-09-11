#include <stdint.h>
#include <stdio.h>




typedef AVExpr;
typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int VAR_B, int VAR_X, int x, int VAR_A, ptrdiff_t width, int VAR_TOP,
    int VAR_BOTTOM, AVExpr * e, double *values, const uint8_t * top,
    uint8_t * dst, const uint8_t * bottom)
{
  for (x = 0; x < width; x++)
    {
      values[VAR_X] = x;
      values[VAR_TOP] = values[VAR_A] = top[x];
      values[VAR_BOTTOM] = values[VAR_B] = bottom[x];
      dst[x] = av_expr_eval (e, values, ((void *) 0));
}}

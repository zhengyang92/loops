#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *xx, int w, float *yy, const float *y, float *xy, const float *x)
{
  IACA_START for (int j = 0; j < w; j++)
    {
      float xval = x[j];
      float yval = y[j];
      float xxval = xval * xval;
      float yyval = yval * yval;
      float xyval = xval * yval;
      xx[j] = xxval;
      yy[j] = yyval;
      xy[j] = xyval;
}IACA_END}

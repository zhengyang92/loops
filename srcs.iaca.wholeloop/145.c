#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float xm, const float ym, const float *y, float num, int size,
    const float *x, float den0)
{
  float den1 = 0.f;
  IACA_START for (int i = 0; i < size; i++)
    {
      float xd = x[i] - xm;
      float yd = y[i] - ym;
      num += xd * yd;
      den0 += xd * xd;
      den1 += yd * yd;
}IACA_END}

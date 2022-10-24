#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *data, float x3, float x4, int period, const float g2, float x1,
    float x2, const float g0, int len, const float g1)
{
  IACA_START for (int i = 0; i < len; i++)
    {
      float x0 = data[i - period + 2];
      data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
      x4 = x3;
      x3 = x2;
      x2 = x1;
      x1 = x0;
}IACA_END}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *data, float x3, float x4, int i, const int T, float g0, float x1,
    float x2, int len, float g1, float x0, float g2)
{
  IACA_START for (i = 0; i < len; i++)
    {
      x0 = data[i - T + 2];
      data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
      x4 = x3;
      x3 = x2;
      x2 = x1;
      x1 = x0;
     } IACA_END
}

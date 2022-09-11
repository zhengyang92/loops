#include <stdint.h>
#include <stdio.h>






int
fn (float *data, float x3, int i, float x4, const int T, float g0, float x1,
    float x2, int len, float x0, float g1, float g2)
{
  for (i = 0; i < len; i++)
    {
      x0 = data[i - T + 2];
      data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
      x4 = x3;
      x3 = x2;
      x2 = x1;
      x1 = x0;
    }
}

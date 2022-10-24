#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *b, const float *a, float *mem, const float *x, float *y,
    int N)
{
  IACA_START for (int i = 0; i < N; i++)
    {
      float xi, yi;
      xi = x[i];
      yi = x[i] + mem[0];
      mem[0] = mem[1] + (b[0] * xi - a[0] * yi);
      mem[1] = (b[1] * xi - a[1] * yi);
      y[i] = yi;
}IACA_END}

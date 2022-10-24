#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *num, float *mem, int len, const float *x, float *y,
    const float *den)
{
  IACA_START for (int i = 0; i < len; i++)
    {
      float yi = num[0] * x[i] + mem[0];
      mem[0] = mem[1] + num[1] * x[i] + -den[1] * yi;
      mem[1] = num[2] * x[i] + -den[2] * yi;
      y[i] = yi;
}IACA_END}

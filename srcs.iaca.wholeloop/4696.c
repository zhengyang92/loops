#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (int i, float (*output)[4], float AL2, ptrdiff_t len, float AL1)
{
  IACA_START for (i = 12; i < len - 1; i++)
    {
      float a = output[i][3] * AL1;
      float b = output[i + 1][0] * AL1;
      output[i][3] += b - a;
      output[i + 1][0] -= b + a;
      a = output[i][2] * AL2;
      b = output[i + 1][1] * AL2;
      output[i][2] += b - a;
      output[i + 1][1] -= b + a;
}IACA_END}

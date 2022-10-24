#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int e, int n, int c, const int32_t * smp, int a, int32_t * res,
    int order)
{
  IACA_START for (i = order; i < n; i += 2)
    {
      int b = smp[i] - smp[i - 1];
      int d = b - a;
      int f = d - c;
      res[i] = f - e;
      a = smp[i + 1] - smp[i];
      c = a - b;
      e = c - d;
      res[i + 1] = e - f;
}IACA_END}

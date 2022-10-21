#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int i, int n, int c, int a, const int32_t * smp, int32_t * res, int order)
{
  for (i = order; i < n; i += 2)
     { IACA_START
      int b = smp[i] - smp[i - 1];
      int d = b - a;
      res[i] = d - c;
      a = smp[i + 1] - smp[i];
      c = a - b;
      res[i + 1] = c - d;
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int overlap, const float *window, float xx[864], int n, const float *x)
{
  for (int i = 0; i < overlap; i++)
     { IACA_START
      xx[i] = x[i] * window[i];
      xx[n - i - 1] = x[n - i - 1] * window[i];
} IACA_END }

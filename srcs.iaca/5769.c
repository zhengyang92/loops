#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float r, float *lpc, float *lpc_last, int j)
{
  for (j = 0; j < (i + 1) >> 1; j++)
     { IACA_START
      float f = lpc_last[j];
      float b = lpc_last[i - 1 - j];
      lpc[j] = f + r * b;
      lpc[i - 1 - j] = b + r * f;
} IACA_END }

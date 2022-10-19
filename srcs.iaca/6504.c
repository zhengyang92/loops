#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, double r, double *lpc_last, double *lpc, int j)
{
  for (j = 0; j < (i + 1) >> 1; j++)
    {
      double f = lpc_last[j];
      double b = lpc_last[i - 1 - j];
      lpc[j] = f + r * b;
      lpc[i - 1 - j] = b + r * f;
}}

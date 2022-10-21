#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;

int
fn (AVComplexFloat x[960])
{
  for (int i = ((120 << 2) + 1); i < (2 * (120 << 2)); i++)
     { IACA_START
      x[i].re = x[(2 * (120 << 2)) - i].re;
      x[i].im = -x[(2 * (120 << 2)) - i].im;
} IACA_END }

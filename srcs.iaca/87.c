#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AVComplexFloat
{
  float re, im;
} AVComplexFloat;

int
fn (const float *in, AVComplexFloat x[960])
{
  for (int i = 0; i < (2 * (120 << 2)); i++)
     { IACA_START
      x[i].re = in[i];
      x[i].im = 0;
} IACA_END }

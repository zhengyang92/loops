#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *coeffs)
{
  float sum = 0.f;
  for (int i = 0; i < 4; i++)
     { IACA_START
      coeffs[i] /= sum;
} IACA_END }

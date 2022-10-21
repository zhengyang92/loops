#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float num, const float scale, const float *const spectral, int size)
{
  float den = 0.f;
  for (int n = 0; n < size; n++)
     { IACA_START
      num += spectral[n] * n * scale;
      den += spectral[n];
} IACA_END }

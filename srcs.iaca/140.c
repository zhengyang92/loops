#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float max, const float *const spectral, int size)
{
  float mean = 0.f;
  for (int n = 0; n < size; n++)
     { IACA_START
      max = fmaxf (max, spectral[n]);
      mean += spectral[n];
} IACA_END }

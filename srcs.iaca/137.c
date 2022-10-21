#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float scale, float centroid, float num, int size,
    const float *const spectral)
{
  float den = 0.f;
  for (int n = 0; n < size; n++)
     { IACA_START
      num += spectral[n] * sqrf (sqrf (n * scale - centroid));
      den += spectral[n];
} IACA_END }

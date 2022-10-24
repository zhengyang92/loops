#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float scale, float centroid, float num, int size,
    const float *const spectral)
{
  float den = 0.f;
  IACA_START for (int n = 0; n < size; n++)
    {
      num += spectral[n] * sqrf (n * scale - centroid);
      den += spectral[n];
}IACA_END}

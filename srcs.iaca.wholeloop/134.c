#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float num, const float scale, const float *const spectral, int size)
{
  float den = 0.f;
  IACA_START for (int n = 0; n < size; n++)
    {
      num += spectral[n] * n * scale;
      den += spectral[n];
}IACA_END}

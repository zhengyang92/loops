#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float num, const float *const spectral, int size)
{
  float den = 0.f;
  IACA_START for (int n = 0; n < size; n++)
    {
      float v = 1.19209290e-7F + spectral[n];
      num += logf (v);
      den += v;
}IACA_END}

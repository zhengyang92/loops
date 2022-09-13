#include <stdint.h>
#include <stdio.h>






int
fn (float num, const float *const spectral, int size)
{
  float den = 0.f;
  for (int n = 1; n < size; n++)
    {
      num += (spectral[n] - spectral[0]) / n;
      den += spectral[n];
}}

#include <stdint.h>
#include <stdio.h>






int
fn (float num, const float *const spectral, int size)
{
  for (int n = 0; n < size; n++)
    {
      num += spectral[n] * logf (spectral[n] + 1.19209290e-7F);
}}

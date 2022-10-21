#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float mean_freq, float num, int size, float mean_spectral,
    const float *const spectral)
{
  float den = 0.f;
  for (int n = 0; n < size; n++)
     { IACA_START
      num += ((n - mean_freq) / mean_freq) * (spectral[n] - mean_spectral);
      den += sqrf ((n - mean_freq) / mean_freq);
} IACA_END }

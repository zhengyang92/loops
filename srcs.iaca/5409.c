#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n, float *coeffs, float *synth_pf)
{
  for (n = 1; n < 64; n++)
     { IACA_START
      float v1 = synth_pf[n * 2], v2 = synth_pf[n * 2 + 1];
      synth_pf[n * 2] = v1 * coeffs[n * 2] - v2 * coeffs[n * 2 + 1];
      synth_pf[n * 2 + 1] = v2 * coeffs[n * 2] + v1 * coeffs[n * 2 + 1];
} IACA_END }

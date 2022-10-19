#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *synth_pf, float *coeffs, int n)
{
  for (n = 1; n < 64; n++)
    {
      float v1 = synth_pf[n * 2], v2 = synth_pf[n * 2 + 1];
      synth_pf[n * 2] = v1 * coeffs[n * 2] - v2 * coeffs[n * 2 + 1];
      synth_pf[n * 2 + 1] = v2 * coeffs[n * 2] + v1 * coeffs[n * 2 + 1];
}}

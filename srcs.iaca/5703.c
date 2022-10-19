#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef struct AacPsyBand
{
  float energy;
  float thr;
  float thr_quiet;
  float nz_lines;
  float active_lines;
  float pe;
  float pe_const;
  float norm_fac;
  int avoid_holes;
} AacPsyBand;
typedef __uint8_t uint8_t;

int
fn (AacPsyBand * band, int g, int i, const float *coefs,
    const uint8_t * band_sizes)
{
  float form_factor = 0.0f;
  int start = 0;
  for (i = 0; i < band_sizes[g]; i++)
    {
      band->energy += coefs[start + i] * coefs[start + i];
      form_factor += sqrtf (fabs (coefs[start + i]));
    }
}

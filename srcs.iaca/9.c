#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int nb_samples, float *dst, int n, float contrast)
{
  for (n = 0; n < nb_samples; n++)
    {
      float d = src[n] * 1.57079632679489661923;
      dst[n] = sinf (d + contrast * sinf (d * 4));
}}

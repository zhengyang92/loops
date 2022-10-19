#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double *src, int nb_samples, int n, float contrast, double *dst)
{
  for (n = 0; n < nb_samples; n++)
    {
      double d = src[n] * 1.57079632679489661923;
      dst[n] = sin (d + contrast * sin (d * 4));
}}

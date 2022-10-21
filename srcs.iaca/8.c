#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double *src, int c, float contrast, int channels, double *dst)
{
  for (c = 0; c < channels; c++)
     { IACA_START
      double d = src[c] * 1.57079632679489661923;
      dst[c] = sin (d + contrast * sin (d * 4));
} IACA_END }

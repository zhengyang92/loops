#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, float *dst, int nb_samples, const float dc)
{
  for (int n = 0; n < nb_samples; n++)
     { IACA_START
      dst[n] = src[n] + dc;
} IACA_END }

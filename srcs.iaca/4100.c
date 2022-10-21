#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *dst, const float *src, const float dc, int nb_samples)
{
  for (int n = 0; n < nb_samples; n++)
     { IACA_START
      dst[n] = src[n] + dc;
} IACA_END }

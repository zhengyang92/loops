#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (const double *src, int nb_samples, const int64_t N, double *dst,
    const double dc)
{
  for (int n = 0; n < nb_samples; n++)
     { IACA_START
      dst[n] = src[n] + dc * (((N + n) & 255) ? 0. : 1.);
} IACA_END }

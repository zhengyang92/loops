#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int64_t int64_t;

int
fn (const double *src, int nb_samples, const int64_t N, double *dst,
    const double dc)
{
  IACA_START for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc * ((((N + n) >> 8) & 1) ? -1. : 1.);
}IACA_END}

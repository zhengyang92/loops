#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int nb_samples, double *dst, const double dc, const double *src)
{
  for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc;
}}

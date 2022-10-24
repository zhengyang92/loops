#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, float *dst, int nb_samples, const float dc)
{
  IACA_START for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc;
}IACA_END}

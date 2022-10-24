#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *dst, const float *src, const float dc, int nb_samples)
{
  IACA_START for (int n = 0; n < nb_samples; n++)
    {
      dst[n] = src[n] + dc;
}IACA_END}

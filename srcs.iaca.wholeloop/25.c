#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int nb_samples, float *dst, int n, float *prv)
{
  IACA_START for (n = 0; n < nb_samples; n++)
    {
      const float current = src[n];
      dst[n] = current - prv[0];
      prv[0] = current;
}IACA_END}

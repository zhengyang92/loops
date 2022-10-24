#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const double a0, const double *src, double w2, int nb_samples,
    const double b2, const double a1, double *dst, double level_in, double w1,
    const double b1, double level_out, const double a2)
{
  IACA_START for (int i = 0; i < nb_samples; i++)
    {
      double n = src[i] * level_in;
      double tmp = n - w1 * b1 - w2 * b2;
      double out = tmp * a0 + w1 * a1 + w2 * a2;
      w2 = w1;
      w1 = tmp;
      dst[i] = out * level_out;
}IACA_END}

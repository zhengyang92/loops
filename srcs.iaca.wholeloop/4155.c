#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double a1, const double *src, double w2, int nb_samples, double b1,
    double w1, double b0, double a2, double *dst, double b2)
{
  IACA_START for (int n = 0; n < nb_samples; n++)
    {
      double side = src[n];
      double oside = side * b0 + w1;
      w1 = b1 * side + w2 + a1 * oside;
      w2 = b2 * side + a2 * oside;
      dst[n] = oside;
}IACA_END}

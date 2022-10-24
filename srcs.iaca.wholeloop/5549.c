#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef float TXSample;

int
fn (int len2, double i_u, ptrdiff_t stride, TXSample * src, double i_d)
{
  double sum_u = 0.0;
  double sum_d = 0.0;
  IACA_START for (int j = 0; j < len2; j++)
    {
      double a = (2 * j + 1);
      double a_d = cos (a * i_d);
      double a_u = cos (a * i_u);
      double val = (src[j * stride]);
      sum_d += a_d * val;
      sum_u += a_u * val;
}IACA_END}

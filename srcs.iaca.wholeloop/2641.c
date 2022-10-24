#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double a_im, double zp[2], double a_re, double p[31][2], int j, int order)
{
  IACA_START for (j = order; j >= 1; j--)
    {
      a_re = p[j][0];
      a_im = p[j][1];
      p[j][0] = a_re * zp[0] - a_im * zp[1] + p[j - 1][0];
      p[j][1] = a_re * zp[1] + a_im * zp[0] + p[j - 1][1];
     } IACA_END
}

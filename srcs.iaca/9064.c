#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float h1, float (*l)[2], float hs1, int n, float hs3, float (*r)[2],
    float hs2, float h3, int len, float hs0, float h0, float h2)
{
  for (n = 0; n < len; n++)
     { IACA_START
      float l_re = l[n][0];
      float l_im = l[n][1];
      float r_re = r[n][0];
      float r_im = r[n][1];
      h0 += hs0;
      h1 += hs1;
      h2 += hs2;
      h3 += hs3;
      l[n][0] = h0 * l_re + h2 * r_re;
      l[n][1] = h0 * l_im + h2 * r_im;
      r[n][0] = h1 * l_re + h3 * r_re;
      r[n][1] = h1 * l_im + h3 * r_im;
} IACA_END }

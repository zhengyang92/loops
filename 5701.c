#include <stdint.h>
#include <stdio.h>






int
fn (float h13, float h10, float hs11, float hs01, float h01, float (*r)[2],
    int len, float h02, float hs03, float hs10, float (*l)[2], float hs13,
    float h00, float h11, float hs02, int n, float h12, float h03, float hs00,
    float hs12)
{
  for (n = 0; n < len; n++)
    {
      float l_re = l[n][0];
      float l_im = l[n][1];
      float r_re = r[n][0];
      float r_im = r[n][1];
      h00 += hs00;
      h01 += hs01;
      h02 += hs02;
      h03 += hs03;
      h10 += hs10;
      h11 += hs11;
      h12 += hs12;
      h13 += hs13;
      l[n][0] = h00 * l_re + h02 * r_re - h10 * l_im - h12 * r_im;
      l[n][1] = h00 * l_im + h02 * r_im + h10 * l_re + h12 * r_re;
      r[n][0] = h01 * l_re + h03 * r_re - h11 * l_im - h13 * r_im;
      r[n][1] = h01 * l_im + h03 * r_im + h11 * l_re + h13 * r_re;
}}

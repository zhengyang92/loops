#include <stdint.h>
#include <stdio.h>






int
fn (const float (*filter)[8][2], int i, float sum_re, float sum_im,
    float (*in)[2], int j)
{
  for (j = 0; j < 6; j++)
    {
      float in0_re = in[j][0];
      float in0_im = in[j][1];
      float in1_re = in[12 - j][0];
      float in1_im = in[12 - j][1];
      sum_re +=
	filter[i][j][0] * (in0_re + in1_re) - filter[i][j][1] * (in0_im -
								 in1_im);
      sum_im +=
	filter[i][j][0] * (in0_im + in1_im) + filter[i][j][1] * (in0_re -
								 in1_re);
}}

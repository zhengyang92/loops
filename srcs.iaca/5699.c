#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float ag[3], const float (*Q_fract)[2], float in_re, int m, int n,
    float in_im, float (*ap_delay)[37][2])
{
  for (m = 0; m < 3; m++)
    {
      float a_re = ag[m] * in_re;
      float a_im = ag[m] * in_im;
      float link_delay_re = ap_delay[m][n + 2 - m][0];
      float link_delay_im = ap_delay[m][n + 2 - m][1];
      float fractional_delay_re = Q_fract[m][0];
      float fractional_delay_im = Q_fract[m][1];
      float apd_re = in_re;
      float apd_im = in_im;
      in_re =
	link_delay_re * fractional_delay_re -
	link_delay_im * fractional_delay_im - a_re;
      in_im =
	link_delay_re * fractional_delay_im +
	link_delay_im * fractional_delay_re - a_im;
      ap_delay[m][n + 5][0] = apd_re + ag[m] * in_re;
      ap_delay[m][n + 5][1] = apd_im + ag[m] * in_im;
}}

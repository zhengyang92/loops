#include <stdint.h>
#include <stdio.h>






int
fn (float pd_re_smooth[512], int pd2, float pd0_re, int pd1,
    const float ipdopd_cos[8], int pd0, float pd0_im, float pd1_re,
    const float ipdopd_sin[8], float pd1_im, float pd_im_smooth[512])
{
  for (pd2 = 0; pd2 < 8; pd2++)
    {
      float pd2_re = ipdopd_cos[pd2];
      float pd2_im = ipdopd_sin[pd2];
      float re_smooth = 0.25f * pd0_re + 0.5f * pd1_re + pd2_re;
      float im_smooth = 0.25f * pd0_im + 0.5f * pd1_im + pd2_im;
      float pd_mag = 1 / hypot (im_smooth, re_smooth);
      pd_re_smooth[pd0 * 64 + pd1 * 8 + pd2] = re_smooth * pd_mag;
      pd_im_smooth[pd0 * 64 + pd1 * 8 + pd2] = im_smooth * pd_mag;
}}

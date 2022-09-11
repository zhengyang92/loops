#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float *const range_table, float fp, float fc,
    const float inv_alpha_, float ycr, const int width,
    const uint16_t * texture_x, float *temp_factor_x, uint16_t tpr, float ypr,
    const uint16_t * in_x, float *temp_x)
{
  for (int x = width - 2; x >= 0; x--)
    {
      uint16_t tcr = *--texture_x;
      uint16_t dr = abs (tcr - tpr);
      int range_dist = dr;
      float alpha_ = range_table[range_dist];
      ycr = inv_alpha_ * (*--in_x) + alpha_ * ypr;
      --temp_x;
      *temp_x = ((*temp_x) + ycr);
      tpr = tcr;
      ypr = ycr;
      fc = inv_alpha_ + alpha_ * fp;
      --temp_factor_x;
      *temp_factor_x = ((*temp_factor_x) + fc);
      fp = fc;
}}

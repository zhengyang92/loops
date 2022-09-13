#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float *const range_table, float fp, float fc,
    const float inv_alpha_, float ycr, const int width,
    const uint16_t * texture_x, float *temp_factor_x, uint16_t tpr, float ypr,
    const uint16_t * in_x, float *temp_x)
{
  for (int x = 1; x < width; x++)
    {
      float alpha_;
      int range_dist;
      uint16_t tcr = *texture_x++;
      uint16_t dr = abs (tcr - tpr);
      range_dist = dr;
      alpha_ = range_table[range_dist];
      *temp_x++ = ycr = inv_alpha_ * (*in_x++) + alpha_ * ypr;
      tpr = tcr;
      ypr = ycr;
      *temp_factor_x++ = fc = inv_alpha_ + alpha_ * fp;
      fp = fc;
}}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * texture_x, const float *const range_table, float fp,
    float fc, const uint8_t * in_x, uint8_t tpr, const float inv_alpha_,
    float ycr, const int width, float *temp_factor_x, float ypr,
    float *temp_x)
{
  for (int x = 1; x < width; x++)
     { IACA_START
      float alpha_;
      int range_dist;
      uint8_t tcr = *texture_x++;
      uint8_t dr = abs (tcr - tpr);
      range_dist = dr;
      alpha_ = range_table[range_dist];
      *temp_x++ = ycr = inv_alpha_ * (*in_x++) + alpha_ * ypr;
      tpr = tcr;
      ypr = ycr;
      *temp_factor_x++ = fc = inv_alpha_ + alpha_ * fp;
      fp = fc;
} IACA_END }

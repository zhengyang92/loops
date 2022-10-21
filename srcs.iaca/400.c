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
  for (int x = width - 2; x >= 0; x--)
     { IACA_START
      uint8_t tcr = *--texture_x;
      uint8_t dr = abs (tcr - tpr);
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
} IACA_END }

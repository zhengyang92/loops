#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * tpy, const float *const range_table, float *ypy_,
    float *ycf_, float *ycy_, const int slice_start, const int slice_end,
    float *factor_, float *out_, const uint8_t * tcy, const float inv_alpha_,
    float *xcf, float *ypf_, float *xcy)
{
  for (int x = 0; x < slice_end - slice_start; x++)
     { IACA_START
      uint8_t dr = abs ((*tcy++) - (*tpy++));
      int range_dist = dr;
      float alpha_ = range_table[range_dist];
      float ycc, fcc = inv_alpha_ * (*xcf++) + alpha_ * (*ypf_++);
      *ycf_++ = fcc;
      *factor_ = (*factor_ + fcc);
      ycc = inv_alpha_ * (*xcy++) + alpha_ * (*ypy_++);
      *ycy_++ = ycc;
      *out_ = (*out_ + ycc) / (*factor_);
      out_++;
      factor_++;
} IACA_END }

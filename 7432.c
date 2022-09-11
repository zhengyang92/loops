#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (const float *const range_table, float *ypy_, float *ycf_,
    const int slice_start, float *ycy_, const int slice_end, float *factor_,
    float *out_, float *xcf, const float inv_alpha_, float *ypf_,
    const uint16_t * tcy, const uint16_t * tpy, float *xcy)
{
  for (int x = 0; x < slice_end - slice_start; x++)
    {
      uint16_t dr = abs ((*tcy++) - (*tpy++));
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
}}

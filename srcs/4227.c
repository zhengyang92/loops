#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * tpy, float *ycf, const float *const range_table,
    float *ycy, const int slice_start, const int slice_end,
    const uint8_t * tcy, const float inv_alpha_, float *xcf, float *ypf,
    float *ypy, float *xcy)
{
  for (int x = 0; x < slice_end - slice_start; x++)
    {
      uint8_t dr = abs ((*tcy++) - (*tpy++));
      int range_dist = dr;
      float alpha_ = range_table[range_dist];
      *ycy++ = inv_alpha_ * (*xcy++) + alpha_ * (*ypy++);
      *ycf++ = inv_alpha_ * (*xcf++) + alpha_ * (*ypf++);
}}

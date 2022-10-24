#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (float *ycf, float *ycy, const float *const range_table,
    const int slice_start, const int slice_end, float *xcf,
    const float inv_alpha_, float *ypf, const uint16_t * tcy,
    const uint16_t * tpy, float *ypy, float *xcy)
{
  IACA_START for (int x = 0; x < slice_end - slice_start; x++)
    {
      uint16_t dr = abs ((*tcy++) - (*tpy++));
      int range_dist = dr;
      float alpha_ = range_table[range_dist];
      *ycy++ = inv_alpha_ * (*xcy++) + alpha_ * (*ypy++);
      *ycf++ = inv_alpha_ * (*xcf++) + alpha_ * (*ypf++);
}IACA_END}

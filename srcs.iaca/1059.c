#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int i, int h, int filt_w, const float *filter,
    int src_stride)
{
  int j = 0;
  float sum = 0.f;
  for (int filt_i = 0; filt_i < filt_w; filt_i++)
     { IACA_START
      const float filt_coeff = filter[filt_i];
      int ii = i - filt_w / 2 + filt_i;
      float img_coeff;
      ii = ii < 0 ? -ii : (ii >= h ? 2 * h - ii - 1 : ii);
      img_coeff = src[ii * src_stride + j];
      sum += filt_coeff * img_coeff;
} IACA_END }

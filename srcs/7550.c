#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, int i, const float *filter, int filt_w, int src_stride)
{
  int j = 0;
  float sum = 0.f;
  for (int filt_i = 0; filt_i < filt_w; filt_i++)
    {
      const float filt_coeff = filter[filt_i];
      float img_coeff;
      int ii = i - filt_w / 2 + filt_i;
      img_coeff = src[ii * src_stride + j];
      sum += filt_coeff * img_coeff;
}}

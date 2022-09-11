#include <stdint.h>
#include <stdio.h>






int
fn (const float *src, float *dst, int c, float contrast, int channels)
{
  for (c = 0; c < channels; c++)
    {
      float d = src[c] * 1.57079632679489661923;
      dst[c] = sinf (d + contrast * sinf (d * 4));
}}

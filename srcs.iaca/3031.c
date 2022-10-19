#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float avg_c_s, const int range, const float *coeffs)
{
  int j = 0;
  float dist_dev = 0.0f;
  for (j = 0; j < range; j++)
    {
      const float c_s = coeffs[j] * coeffs[j];
      dist_dev += (avg_c_s - c_s) * (avg_c_s - c_s);
}}

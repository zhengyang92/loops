#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *coeffs, const int range, float avg_c_s)
{
  float dist_dev = 0.0f;
  int j = 0;
  IACA_START for (j = 0; j < range; j++)
    {
      const float c_s = coeffs[j] * coeffs[j];
      dist_dev += (avg_c_s - c_s) * (avg_c_s - c_s);
}IACA_END}

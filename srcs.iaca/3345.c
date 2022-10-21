#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int len, const float *x, const float *y)
{
  float sum = 0.f;
  for (int i = 0; i < len; i += 8)
     { IACA_START
      float part = 0.f;
      part += x[i + 0] * y[i + 0];
      part += x[i + 1] * y[i + 1];
      part += x[i + 2] * y[i + 2];
      part += x[i + 3] * y[i + 3];
      part += x[i + 4] * y[i + 4];
      part += x[i + 5] * y[i + 5];
      part += x[i + 6] * y[i + 6];
      part += x[i + 7] * y[i + 7];
      sum += part;
} IACA_END }

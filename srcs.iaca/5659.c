#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float *vec, const float IQ, const int dim, int j,
    const float *in)
{
  float rd = 0.0f;
  for (j = 0; j < dim; j++)
     { IACA_START
      float di = in[i + j] - vec[j] * IQ;
      rd += di * di;
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *diff_isf, int i, int lag, float mean, float sum)
{
  for (i = 7; i < 16 - 2; i++)
    {
      float prod = (diff_isf[i] - mean) * (diff_isf[i - lag] - mean);
      sum += prod * prod;
}}

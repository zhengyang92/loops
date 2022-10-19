#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *tab0, float tmp1, float tmp0, int len, float *tab1, int j)
{
  for (j = 0; j < len; j++)
    {
      tmp0 = tab0[j];
      tmp1 = tab1[j];
      tab0[j] = ((((float) (0.70710678118654752440))) * (tmp0 + tmp1));
      tab1[j] = ((((float) (0.70710678118654752440))) * (tmp0 - tmp1));
}}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *samples_l, int j, float *samples_r)
{
  for (j = 0; j < 16; j++)
    {
      float tmp = samples_l[j];
      samples_l[j] = (tmp + samples_r[j]) * 0.5f;
      samples_r[j] = (tmp - samples_r[j]) * 0.5f;
}}

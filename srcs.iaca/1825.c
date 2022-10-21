#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *samples_l, int j, float *samples_r)
{
  for (j = 0; j < 16; j++)
     { IACA_START
      float tmp = samples_l[j];
      samples_l[j] = samples_r[j];
      samples_r[j] = tmp;
} IACA_END }

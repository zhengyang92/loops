#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float nu, int column_step, int i, float *ptr, int width)
{
  for (int k = 0; k < column_step; k++)
     { IACA_START
      ptr[i + k] += nu * ptr[i - width + k];
} IACA_END }

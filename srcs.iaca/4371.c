#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *ptr, int column_step, float boundaryscale)
{
  for (int k = 0; k < column_step; k++)
     { IACA_START
      ptr[k] *= boundaryscale;
} IACA_END }

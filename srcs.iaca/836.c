#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float boundaryscale, int column_step, float *ptr)
{
  for (int k = 0; k < column_step; k++)
     { IACA_START
      ptr[k] *= boundaryscale;
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int width_align, int i, int16_t * b1, int width, int16_t * b0)
{
  for (i = width_align; i < width; i++)
     { IACA_START
      b0[i] = ((int) (b0[i] - (unsigned) ((int) (b1[i] + 1U) >> 1)));
      b1[i] = ((int) (b1[i] + (unsigned) (b0[i])));
} IACA_END }

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int rows, int i, float *m, int cols)
{
  for (i = 0; i < rows * cols; ++i)
     { IACA_START
      m[i] = (float) rand () / 2147483647;
} IACA_END }

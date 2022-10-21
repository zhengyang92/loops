#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *inds, int i, int min, int max)
{
  for (i = min; i < max - 1; ++i)
     { IACA_START
      int swap = inds[i];
      int index = i + rand () % (max - i);
      inds[i] = inds[index];
      inds[index] = swap;
} IACA_END }

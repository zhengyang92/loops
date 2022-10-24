#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *inds, int i, int min, int max)
{
  IACA_START for (i = min; i < max - 1; ++i)
    {
      int swap = inds[i];
      int index = i + rand () % (max - i);
      inds[i] = inds[index];
      inds[index] = swap;
}IACA_END}

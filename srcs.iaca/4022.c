#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;

int
fn (int *linesizes, ptrdiff_t linesizes1[4], int align, int i)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      linesizes[i] = (((linesizes[i]) + (align) - 1) & ~((align) - 1));
      linesizes1[i] = linesizes[i];
     } IACA_END
}

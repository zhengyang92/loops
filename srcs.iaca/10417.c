#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int *indexes, int top)
{
  for (j = 0; j < top; ++j)
     { IACA_START
      printf ("\t%d", indexes[j]);
     } IACA_END
}

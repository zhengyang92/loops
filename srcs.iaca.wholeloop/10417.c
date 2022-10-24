#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int *indexes, int top)
{
  IACA_START for (j = 0; j < top; ++j)
    {
      printf ("\t%d", indexes[j]);
     } IACA_END
}

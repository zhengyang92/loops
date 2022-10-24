#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *pred, int j, int classes)
{
  IACA_START for (j = 0; j < classes; ++j)
    {
      printf ("\t%g", pred[j]);
     } IACA_END
}

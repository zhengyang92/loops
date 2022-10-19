#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *pred, int j, int classes)
{
  for (j = 0; j < classes; ++j)
    {
      printf ("\t%g", pred[j]);
    }
}

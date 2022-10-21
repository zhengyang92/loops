#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int i, int els, float **a, float *avg)
{
  for (i = 0; i < els; ++i)
     { IACA_START
      avg[i] += a[j][i];
     } IACA_END
}

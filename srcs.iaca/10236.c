#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *avg, int n, int i, int els)
{
  for (i = 0; i < els; ++i)
     { IACA_START
      avg[i] /= n;
     } IACA_END
}

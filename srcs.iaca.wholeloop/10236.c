#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *avg, int n, int i, int els)
{
  IACA_START for (i = 0; i < els; ++i)
    {
      avg[i] /= n;
     } IACA_END
}

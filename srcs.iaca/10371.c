#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n, float *truth, int i)
{
  for (; i < n; ++i)
     { IACA_START
      truth[i * 37 + 37 - 1] = 1;
     } IACA_END
}

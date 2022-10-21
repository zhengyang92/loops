#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *a, float s, int n, int i)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      a[i] += s;
     } IACA_END
}

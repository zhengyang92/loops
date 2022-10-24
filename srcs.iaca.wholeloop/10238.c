#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *a, float s, int n, int i)
{
  IACA_START for (i = 0; i < n; ++i)
    {
      a[i] += s;
     } IACA_END
}

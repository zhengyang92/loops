#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *a, float r, int i, int n)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      r = r - a[i];
      if (r <= 0)
	return i;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *a, int n, int i, float max)
{
  int max_i = 0;
  for (i = 1; i < n; ++i)
     { IACA_START
      if (a[i] > max)
	{
	  max = a[i];
	  max_i = i;
	}
     } IACA_END
}

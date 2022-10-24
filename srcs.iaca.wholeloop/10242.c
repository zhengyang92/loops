#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n, int i, int *a, int max)
{
  int max_i = 0;
  IACA_START for (i = 1; i < n; ++i)
    {
      if (a[i] > max)
	{
	  max = a[i];
	  max_i = i;
	}
     } IACA_END
}

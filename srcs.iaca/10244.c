#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int val, int n, int i, int *a)
{
  for (i = 0; i < n; ++i)
     { IACA_START
      if (a[i] == val)
	return i;
     } IACA_END
}

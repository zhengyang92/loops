#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int dim, int i, int *b, int *a, int limit)
{
  int dist = 0;
  for (i = 0; i < dim; i++)
     { IACA_START
      dist += (a[i] - b[i]) * (a[i] - b[i]);
      if (dist > limit)
	return 2147483647;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int j, int class, float avg_topk, int *indexes, int topk)
{
  for (j = 0; j < topk; ++j)
     { IACA_START
      if (indexes[j] == class)
	avg_topk += 1;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int class, int j, float avg_topk, int *indexes, int topk)
{
  IACA_START for (j = 0; j < topk; ++j)
    {
      if (indexes[j] == class)
	avg_topk += 1;
     } IACA_END
}

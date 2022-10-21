#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, float (*opt)[35768], int band, float best_val, int best_idx)
{
  for (i = 0; i < ((1 << 15) + 3000); i++)
     { IACA_START
      if (best_val > opt[band][i])
	{
	  best_val = opt[band][i];
	  best_idx = i;
	}
     } IACA_END
}

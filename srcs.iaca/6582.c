#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int32_t scale_factor_mult[15][3])
{
  for (i = 0; i < 15; i++)
     { IACA_START
      int n, norm;
      n = i + 2;
      norm = ((1L << n) * (1 << 23)) / ((1 << n) - 1);
      scale_factor_mult[i][0] = ((((float) (1.0 * 2.0))) * (norm));
      scale_factor_mult[i][1] = ((((float) (0.7937005259 * 2.0))) * (norm));
      scale_factor_mult[i][2] = ((((float) (0.6299605249 * 2.0))) * (norm));
      do
	{
	}
      while (0);
     } IACA_END
}

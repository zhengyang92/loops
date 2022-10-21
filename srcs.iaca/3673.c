#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double tmp, double *lsps, int l, int m)
{
  for (l = m - 1; l >= 0; l--)
     { IACA_START
      if (lsps[l] <= tmp)
	break;
      lsps[l + 1] = lsps[l];
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *lsps, double tmp, int l, int m)
{
  IACA_START for (l = m - 1; l >= 0; l--)
    {
      if (lsps[l] <= tmp)
	break;
      lsps[l + 1] = lsps[l];
     } IACA_END
}

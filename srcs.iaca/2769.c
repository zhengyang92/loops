#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double scale, int order, int i, double *lpc_in)
{
  for (i = 0; i < order; i++)
     { IACA_START
      lpc_in[i] *= scale;
     } IACA_END
}

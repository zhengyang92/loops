#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double scale, int i, double *lpc_in, int order)
{
  for (i = 0; i < order; i++)
     { IACA_START
      lpc_in[i] *= scale;
     } IACA_END
}

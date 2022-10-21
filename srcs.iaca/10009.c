#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n, int accum[4], const int nb, int dist_accum[4])
{
  for (n = 0; n < nb; ++n)
     { IACA_START
      accum[n] = 0;
      dist_accum[n] = 0;
     } IACA_END
}

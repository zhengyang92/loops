#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int (*W)[2], int k, const int *z)
{
  for (k = 0; k < 32; k++)
     { IACA_START
      W[k][0] = -z[63 - k];
      W[k][1] = z[k];
     } IACA_END
}

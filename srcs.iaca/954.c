#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int c, int sum[3])
{
  for (c = 0; c < 3; c++)
     { IACA_START
      sum[c] = 0;
     } IACA_END
}

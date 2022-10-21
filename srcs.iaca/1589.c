#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int b3_mantissas[8])
{
  for (i = 0; i < 7; i++)
     { IACA_START
      b3_mantissas[i] = symmetric_dequant (i, 7);
     } IACA_END
}

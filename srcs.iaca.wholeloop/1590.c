#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int b5_mantissas[16], int i)
{
  IACA_START for (i = 0; i < 15; i++)
    {
      b5_mantissas[i] = symmetric_dequant (i, 15);
     } IACA_END
}

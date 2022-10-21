#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int o_16[8], int e_16[8], int i, int e_32[16])
{
  for (i = 0; i < 8; i++)
     { IACA_START
      (e_32[i * 1]) = (e_16[i] + o_16[i]);
      (e_32[(15 - i) * 1]) = (e_16[i] - o_16[i]);
     } IACA_END
}

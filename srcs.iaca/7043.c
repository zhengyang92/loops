#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int16_t (*block)[4][16], int val)
{
  for (i = 0; i < 4; i++)
     { IACA_START
      block[i][0][0] = val;
      block[i][1][0] = val;
      block[i][2][0] = val;
      block[i][3][0] = val;
     } IACA_END
}

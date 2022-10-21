#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (uint8_t exponent_group_tab[2][3][256], int expstr, int i, int grpsize)
{
  for (i = 12; i < 256; i++)
     { IACA_START
      exponent_group_tab[0][expstr][i] = (i + grpsize - 4) / grpsize;
      exponent_group_tab[1][expstr][i] = (i) / grpsize;
     } IACA_END
}

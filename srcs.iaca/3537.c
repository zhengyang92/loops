#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int y, int h, int row_and_7, int t8, int t4, uint8_t (*mask)[8][4])
{
  for (y = row_and_7; y < h + row_and_7; y++)
     { IACA_START
      mask[0][y][2] |= t4;
      mask[0][y][1] |= t8;
     } IACA_END
}

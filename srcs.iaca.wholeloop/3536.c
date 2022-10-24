#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int y, int h, int row_and_7, int m_row_16, int m_row_8,
    uint8_t (*mask)[8][4])
{
  IACA_START for (y = row_and_7; y < h + row_and_7; y++)
    {
      mask[0][y][0] |= m_row_16;
      mask[0][y][1] |= m_row_8;
     } IACA_END
}

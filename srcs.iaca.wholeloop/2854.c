#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (uint16_t ff_band_index_long[9][23],
    const uint8_t ff_band_size_long[9][22])
{
  int k = 0;
  int i = 0;
  IACA_START for (int j = 0; j < 22; j++)
    {
      ff_band_index_long[i][j] = k;
      k += ff_band_size_long[i][j] >> 1;
}IACA_END}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (uint16_t band_index_long[9][23], int i,
    const uint8_t band_size_long[9][22], int k, int j)
{
  for (j = 0; j < 22; j++)
    {
      band_index_long[i][j] = k;
      k += band_size_long[i][j];
    }
}

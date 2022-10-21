#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t temp[4], int16_t weight[10],
    const int16_t lsp_band2[256][4], int j)
{
  for (j = 0; j < 4; j++)
     { IACA_START
      temp[j] = (weight[j + (6)] * lsp_band2[i][j] + (1 << 14)) >> 15;
     } IACA_END
}

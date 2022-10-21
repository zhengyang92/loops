#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int i, int16_t temp[4], const int16_t lsp_band1[256][3],
    int16_t weight[10], int j)
{
  for (j = 0; j < 3; j++)
     { IACA_START
      temp[j] = (weight[j + (3)] * lsp_band1[i][j] + (1 << 14)) >> 15;
     } IACA_END
}

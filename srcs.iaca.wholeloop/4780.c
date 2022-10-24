#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int temp, int i, const int16_t dc_lsp[10], int pred, int16_t * prev_lsp,
    int16_t * cur_lsp)
{
  IACA_START for (i = 0; i < 10; i++)
    {
      temp = ((prev_lsp[i] - dc_lsp[i]) * pred + (1 << 14)) >> 15;
      cur_lsp[i] += dc_lsp[i] + temp;
     } IACA_END
}

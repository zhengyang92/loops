#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (const int16_t dc_lsp[10], int i, int16_t * lsp, int16_t * prev_lsp)
{
  IACA_START for (i = 0; i < 10; i++)
    {
      lsp[i] -=
	dc_lsp[i] + (((prev_lsp[i] - dc_lsp[i]) * 12288 + (1 << 14)) >> 15);
     } IACA_END
}

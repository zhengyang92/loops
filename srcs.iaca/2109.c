#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t * prev_lsp, const int16_t dc_lsp[10], int16_t * lsp, int i)
{
  for (i = 0; i < 10; i++)
     { IACA_START
      lsp[i] -=
	dc_lsp[i] + (((prev_lsp[i] - dc_lsp[i]) * 12288 + (1 << 14)) >> 15);
     } IACA_END
}

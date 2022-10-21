#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int f[12], int16_t * lsp, int i)
{
  for (i = 0; i < 10 / 2; i++)
     { IACA_START
      f[2 * i + 2] = -f[2 * i] - ((lsp[i] + lsp[10 - 1 - i]) << 12);
      f[2 * i + 3] = f[2 * i + 1] - ((lsp[i] - lsp[10 - 1 - i]) << 12);
     } IACA_END
}

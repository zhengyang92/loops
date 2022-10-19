#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int16_t weight[10], int16_t min, int16_t * lsp, int i)
{
  for (i = 1; i < 10 - 1; i++)
    {
      min =
	((lsp[i] - lsp[i - 1]) >
	 (lsp[i + 1] - lsp[i]) ? (lsp[i + 1] - lsp[i]) : (lsp[i] -
							  lsp[i - 1]));
      if (min > 0x20)
	weight[i] = (1 << 20) / min;
      else
	weight[i] = (32767);
    }
}

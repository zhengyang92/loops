#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;

int
fn (int temp, int min_dist, int16_t * cur_lsp, int j, int stable)
{
  IACA_START for (j = 1; j < 10; j++)
    {
      temp = cur_lsp[j - 1] + min_dist - cur_lsp[j] - 4;
      if (temp > 0)
	{
	  stable = 0;
	  break;
	}
     } IACA_END
}

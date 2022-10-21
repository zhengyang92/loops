#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef EncBlockInfo;

int
fn (int size[5], int i, EncBlockInfo * b, uint16_t size_cache[40][31], int j,
    int qlevels[5])
{
  for (j = 0; j < 8; j++, b++)
     { IACA_START
      if (size_cache[8 * i + j][qlevels[i]] == 0)
	{
	  size_cache[8 * i + j][qlevels[i]] =
	    dv100_actual_quantize (b, qlevels[i]);
	}
      size[i] += size_cache[8 * i + j][qlevels[i]];
     } IACA_END
}

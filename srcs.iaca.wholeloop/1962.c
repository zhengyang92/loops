#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef EncBlockInfo;

int
fn (int size[5], int i, EncBlockInfo * blks, uint16_t size_cache[40][31],
    int j, int qlevels[5])
{
  IACA_START for (j = 0; j < 8; j++)
    {
      size_cache[8 * i + j][qlevels[i]] =
	dv100_actual_quantize (&blks[8 * i + j], qlevels[i]);
      size[i] += size_cache[8 * i + j][qlevels[i]];
     } IACA_END
}

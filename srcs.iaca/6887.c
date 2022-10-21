#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int stages, unsigned int level, uint32_t bit_cache, int j, int entries[6])
{
  for (j = 0; j < stages; j++)
     { IACA_START
      entries[j] =
	(((bit_cache >> (4 * (stages - j - 1))) & 0xF) + 16 * j) << (level +
								     1);
     } IACA_END
}

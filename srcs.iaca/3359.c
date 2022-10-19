#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int stages, uint32_t bit_cache, int level, int j, int entries[6])
{
  for (j = 0; j < stages; j++)
    {
      entries[j] =
	(((bit_cache >> (4 * (stages - j - 1))) & 0xF) + 16 * j) << (level +
								     1);
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t random_seed, float delta, float noise_table[4116], int i)
{
  IACA_START for (i = 0; i < 4096; i++)
    {
      random_seed = random_seed * 214013 + 2531011;
      noise_table[i] =
	(delta * (float) (((int32_t) random_seed >> 16) & 0x00007FFF) -
	 1.0) * 1.3;
}IACA_END}

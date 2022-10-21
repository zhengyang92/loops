#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint16_t uint16_t;

int
fn (uint16_t * codebook_multiplicands, unsigned int codebook_value_bits,
    unsigned int i, unsigned int codebook_lookup_values, GetBitContext * gb)
{
  for (i = 0; i < codebook_lookup_values; ++i)
     { IACA_START
      codebook_multiplicands[i] = get_bits (gb, codebook_value_bits);
      do
	{
	}
      while (0);
      do
	{
	}
      while (0);
     } IACA_END
}

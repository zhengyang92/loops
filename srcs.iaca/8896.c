#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint16_t uint16_t;

int
fn (float codebook_minimum_value, uint16_t * codebook_multiplicands,
    unsigned int codebook_value_bits, float codebook_delta_value,
    unsigned int i, unsigned int codebook_lookup_values, GetBitContext * gb)
{
  for (i = 0; i < codebook_lookup_values; ++i)
     { IACA_START
      codebook_multiplicands[i] = get_bits (gb, codebook_value_bits);
      do
	{
	  if (0)
	    av_log (((void *) 0), 48, " multiplicands*delta+minmum : %e \n",
		    (float) codebook_multiplicands[i] * codebook_delta_value +
		    codebook_minimum_value);
	}
      while (0);
      do
	{
	  if (0)
	    av_log (((void *) 0), 48, " multiplicand %u\n",
		    codebook_multiplicands[i]);
	}
      while (0);
     } IACA_END
}

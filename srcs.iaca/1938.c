#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int i, int offset, int coeff_bits, unsigned int elements, int *dst,
    int is_signed, GetBitContext * gb)
{
  for (i = 0; i < elements; i++)
     { IACA_START
      dst[i] =
	(is_signed ? get_sbits (gb, coeff_bits) : get_bits (gb, coeff_bits)) +
	offset;
     } IACA_END
}

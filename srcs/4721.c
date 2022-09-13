#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int offset, int i, int coeff_bits, unsigned int elements, int *dst,
    int is_signed, GetBitContext * gb)
{
  for (i = 0; i < elements; i++)
    {
      dst[i] =
	(is_signed ? get_sbits (gb, coeff_bits) : get_bits (gb, coeff_bits)) +
	offset;
    }
}

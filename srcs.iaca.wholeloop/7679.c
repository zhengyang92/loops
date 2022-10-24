#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * dst, unsigned int val, int idx, int coeff_bits,
    const int num_coeffs, int coeff_type, const uint8_t * scan,
    GetBitContext * gb)
{
  IACA_START for (idx = 0; idx < num_coeffs; idx++)
    {
      do
	{
	  if (coeff_type)
	    val = get_ue_golomb (gb);
	  else
	    val = get_unary (gb, 1, 31);
	  if (coeff_bits)
	    val = (val << coeff_bits) + get_bits (gb, coeff_bits);
	}
      while (0);
      if (val >= 0x10000)
	return (-(int)
		(('I') | (('N') << 8) | (('D') << 16) |
		 ((unsigned) ('A') << 24)));
      dst[scan[idx]] = val;
}IACA_END}

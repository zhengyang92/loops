#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int skip_bits, int slice_width, int16_t * dst, int idx, unsigned int val,
    int coeff_bits, const int num_coeffs, int coeff_type, int mb,
    int skip_type, const uint8_t * scan, GetBitContext * gb)
{
  for (mb = 0; mb < slice_width; mb++)
     { IACA_START
      idx = -1;
      do
	{
	  do
	    {
	      if (skip_type)
		val = get_ue_golomb (gb);
	      else
		val = get_unary (gb, 1, 31);
	      if (skip_bits)
		val = (val << skip_bits) + get_bits (gb, skip_bits);
	    }
	  while (0);
	  if (val >= 0x10000)
	    return (-(int)
		    (('I') | (('N') << 8) | (('D') << 16) |
		     ((unsigned) ('A') << 24)));
	  idx += val + 1;
	  if (idx >= num_coeffs)
	    break;
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
	  val++;
	  if (val >= 0x10000)
	    return (-(int)
		    (('I') | (('N') << 8) | (('D') << 16) |
		     ((unsigned) ('A') << 24)));
	  dst[scan[idx]] = val;
	}
      while (idx < num_coeffs - 1);
      dst += num_coeffs;
     } IACA_END
}

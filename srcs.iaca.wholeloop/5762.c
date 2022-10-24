#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int skip_bits, int slice_width, int val, int16_t * dst, int idx,
    BitstreamContext * bc, int coeff_bits, const int num_coeffs,
    int coeff_type, int mb, int skip_type, const uint8_t * scan)
{
  IACA_START for (mb = 0; mb < slice_width; mb++)
    {
      idx = -1;
      do
	{
	  do
	    {
	      if (skip_type)
		val = get_ue_golomb (bc);
	      else
		val = get_unary (bc, 1, 31);
	      if (skip_bits)
		val = (val << skip_bits) + bitstream_read (bc, skip_bits);
	    }
	  while (0);
	  if (val < 0)
	    return (-0x3ebbb1b7);
	  idx += val + 1;
	  if (idx >= num_coeffs)
	    break;
	  do
	    {
	      if (coeff_type)
		val = get_ue_golomb (bc);
	      else
		val = get_unary (bc, 1, 31);
	      if (coeff_bits)
		val = (val << coeff_bits) + bitstream_read (bc, coeff_bits);
	    }
	  while (0);
	  val++;
	  if (val >= 0x10000 || val < 0)
	    return (-0x3ebbb1b7);
	  dst[scan[idx]] = val;
	}
      while (idx < num_coeffs - 1);
      dst += num_coeffs;
     } IACA_END
}

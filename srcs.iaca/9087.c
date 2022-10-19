#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int16_t * dst, int val, int idx, BitstreamContext * bc, int coeff_bits,
    const int num_coeffs, int coeff_type, const uint8_t * scan)
{
  for (idx = 0; idx < num_coeffs; idx++)
    {
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
      if (val >= 0x10000 || val < 0)
	return (-0x3ebbb1b7);
      dst[scan[idx]] = val;
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;

int
fn (int bits, int part0, int j, int *sample_buf, GetBitContext * gb)
{
  for (j = 0; j < part0; j++)
     { IACA_START
      int t = get_unary (gb, 1, 33) << bits;
      if (bits)
	t |= get_bits (gb, bits);
      sample_buf[j] = (t & 1) ? -(t >> 1) - 1 : (t >> 1);
     } IACA_END
}

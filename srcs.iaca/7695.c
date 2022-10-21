#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int16_t int16_t;

int
fn (int i, int bits, unsigned int val, int16_t * out, int cf, int is_signed,
    int pos, int num_coeffs, GetBitContext * gb)
{
  for (i = 0; i < num_coeffs; i++)
     { IACA_START
      cf = av_mod_uintp2_c (val, bits);
      if (is_signed)
	cf = sign_extend (cf, bits);
      else if (cf && get_bits1 (gb))
	cf = -cf;
      out[pos++] = cf;
      val >>= bits;
     } IACA_END
}

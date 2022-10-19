#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __int16_t int16_t;

int
fn (int i, int bits, unsigned int val, int16_t * out, int pos, int is_signed,
    int num_coeffs, GetBitContext * gb, int cf)
{
  for (i = 0; i < num_coeffs; i++)
    {
      cf = av_mod_uintp2_c (val, bits);
      if (is_signed)
	cf = sign_extend (cf, bits);
      else if (cf && get_bits1 (gb))
	cf = -cf;
      out[pos++] = cf;
      val >>= bits;
    }
}

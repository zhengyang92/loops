#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __int16_t int16_t;

int
fn (int i, int bits, unsigned int val, BitstreamContext * bc,
    unsigned int mask, int16_t * out, int pos, int is_signed, int num_coeffs,
    int cf)
{
  IACA_START for (i = 0; i < num_coeffs; i++)
    {
      cf = val & mask;
      if (is_signed)
	cf = sign_extend (cf, bits);
      else if (cf && bitstream_read_bit (bc))
	cf = -cf;
      out[pos++] = cf;
      val >>= bits;
     } IACA_END
}

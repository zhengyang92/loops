#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int prev_dc, int i, int *qmat, int idx, int delta, int sign, int16_t * in,
    int new_dc, int blocks_per_slice, int code, int diff_sign,
    PutBitContext * pb, const uint8_t dc_codebook[7], int new_code)
{
  IACA_START for (i = 1; i < blocks_per_slice; i++, idx += 64)
    {
      new_dc = ((in[idx] - 16384) / ((qmat)[0]));
      delta = new_dc - prev_dc;
      diff_sign = (((delta) >> 31) ^ (sign));
      new_code =
	((get_level (delta)) ==
	 0 ? 0 : ((get_level (delta)) << 1) + (diff_sign));
      encode_codeword (pb, new_code,
		       dc_codebook[((code) > (6) ? (6) : (code))]);
      code = new_code;
      sign = delta >> 31;
      prev_dc = new_dc;
     } IACA_END
}

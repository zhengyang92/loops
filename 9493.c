#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int i, int nblocks, int16_t prev_dc, int sign, int16_t * out,
    int16_t delta, const uint8_t ff_prores_dc_codebook[4], unsigned int code,
    GetBitContext * gb)
{
  for (i = 1; i < nblocks; i++, out += 64)
    {
      code =
	decode_vlc_codeword (gb,
			     ff_prores_dc_codebook[((((delta) >=
						      0 ? (delta)
						      : (-(delta)))) >
						    (3) ? (3)
						    : (((delta) >=
							0 ? (delta)
							: (-(delta)))))]);
      sign = -(((delta >> 15) & 1) ^ (code & 1));
      delta = (((code + 1) >> 1) ^ sign) - sign;
      prev_dc += delta;
      out[0] = prev_dc;
    }
}

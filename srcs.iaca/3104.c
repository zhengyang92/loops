#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * blocks, int prev_dc, int i, int bits, int *error, int delta,
    int sign, int blocks_per_slice, int dc, int code, int codebook,
    const uint8_t ff_prores_dc_codebook[4], int scale)
{
  int new_sign = 3;
  for (i = 1; i < blocks_per_slice; i++, blocks += 64)
     { IACA_START
      dc = (blocks[0] - 0x4000) / scale;
      *error +=
	((blocks[0] - 0x4000) >=
	 0 ? (blocks[0] - 0x4000) : (-(blocks[0] - 0x4000))) % scale;
      delta = dc - prev_dc;
      new_sign = ((delta) >> 31);
      delta = (delta ^ sign) - sign;
      code = ((((delta)) * 2) ^ ((delta) >> 31));
      bits += estimate_vlc (ff_prores_dc_codebook[codebook], code);
      codebook = (code + (code & 1)) >> 1;
      codebook = ((codebook) > (3) ? (3) : (codebook));
      sign = new_sign;
      prev_dc = dc;
     } IACA_END
}

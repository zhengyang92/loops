#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const uint8_t * scan, int max_coeffs, int bits_left,
    const uint8_t ff_prores_run_to_cb_index[16], int sign,
    int blocks_per_slice, int run, int level, int lev_cb_index, int16_t * out,
    int block_mask, int pos, int plane_size_factor,
    const uint8_t ff_prores_ac_codebook[7],
    const uint8_t ff_prores_lev_to_cb_index[10], GetBitContext * gb,
    int run_cb_index)
{
  for (pos = blocks_per_slice - 1; pos < max_coeffs;)
     { IACA_START
      run_cb_index = ff_prores_run_to_cb_index[((run) > (15) ? (15) : (run))];
      lev_cb_index =
	ff_prores_lev_to_cb_index[((level) > (9) ? (9) : (level))];
      bits_left = get_bits_left (gb);
      if (bits_left <= 0 || (bits_left <= 16 && !show_bits (gb, bits_left)))
	return 0;
      run = decode_vlc_codeword (gb, ff_prores_ac_codebook[run_cb_index]);
      if (run < 0)
	return (-0x3ebbb1b7);
      bits_left = get_bits_left (gb);
      if (bits_left <= 0 || (bits_left <= 16 && !show_bits (gb, bits_left)))
	return (-0x3ebbb1b7);
      level =
	decode_vlc_codeword (gb, ff_prores_ac_codebook[lev_cb_index]) + 1;
      if (level < 0)
	return (-0x3ebbb1b7);
      pos += run + 1;
      if (pos >= max_coeffs)
	break;
      sign = get_sbits (gb, 1);
      out[((pos & block_mask) << 6) + scan[pos >> plane_size_factor]] =
	(level ^ sign) - sign;
     } IACA_END
}

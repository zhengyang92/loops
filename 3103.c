#include <stdint.h>
#include <stdio.h>




typedef PutBitContext;
typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * blocks, int run_cb, const uint8_t ff_prores_lev_to_cb_index[10],
    int i, int max_coeffs, int idx, const uint8_t ff_prores_ac_codebook[7],
    int abs_level, const int16_t * qmat, int level, int lev_cb,
    PutBitContext * pb, const uint8_t * scan,
    const uint8_t ff_prores_run_to_cb_index[16], int run)
{
  for (idx = scan[i]; idx < max_coeffs; idx += 64)
    {
      level = blocks[idx] / qmat[scan[i]];
      if (level)
	{
	  abs_level = ((level) >= 0 ? (level) : (-(level)));
	  encode_vlc_codeword (pb, ff_prores_ac_codebook[run_cb], run);
	  encode_vlc_codeword (pb, ff_prores_ac_codebook[lev_cb],
			       abs_level - 1);
	  put_sbits (pb, 1, ((level) >> 31));
	  run_cb = ff_prores_run_to_cb_index[((run) > (15) ? (15) : (run))];
	  lev_cb =
	    ff_prores_lev_to_cb_index[((abs_level) >
				       (9) ? (9) : (abs_level))];
	  run = 0;
	}
      else
	{
	  run++;
	}
    }
}

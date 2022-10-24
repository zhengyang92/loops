#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int16_t * blocks, int run_cb, int i, int max_coeffs, int idx, int *error,
    const uint8_t ff_prores_run_to_cb_index[16],
    const uint8_t ff_prores_ac_codebook[7], int abs_level,
    const int16_t * qmat, int lev_cb, int level, const uint8_t * scan,
    const uint8_t ff_prores_lev_to_cb_index[10], int run)
{
  int bits = 0;
  IACA_START for (idx = scan[i]; idx < max_coeffs; idx += 64)
    {
      level = blocks[idx] / qmat[scan[i]];
      *error +=
	((blocks[idx]) >=
	 0 ? (blocks[idx]) : (-(blocks[idx]))) % qmat[scan[i]];
      if (level)
	{
	  abs_level = ((level) >= 0 ? (level) : (-(level)));
	  bits += estimate_vlc (ff_prores_ac_codebook[run_cb], run);
	  bits +=
	    estimate_vlc (ff_prores_ac_codebook[lev_cb], abs_level - 1) + 1;
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
     } IACA_END
}

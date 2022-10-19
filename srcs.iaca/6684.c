#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (float *cand, int *idx_table, float power_candidate, int band,
    const uint8_t sf_delta_lut[78], const int16_t ff_nelly_delta_table[32],
    int best_idx)
{
  int power_idx = 0;
  for (band = 1; band < 23; band++)
    {
      power_candidate = cand[band] - power_idx;
      best_idx =
	sf_delta_lut[av_clip_c
		     ((lrintf (power_candidate) >> 8) + 37, 0, 78 - 1)];
      if (fabs (power_candidate - ff_nelly_delta_table[best_idx]) >
	  fabs (power_candidate - ff_nelly_delta_table[best_idx + 1]))
	best_idx++;;
      idx_table[band] = best_idx;
      power_idx += ff_nelly_delta_table[best_idx];
    }
}

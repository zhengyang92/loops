#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef int INTFLOAT;

int
fn (int i, INTFLOAT (*transient_gain)[32], INTFLOAT * power_smooth, int n0,
    int n, INTFLOAT * peak_decay_nrg, const INTFLOAT peak_decay_factor,
    INTFLOAT * peak_decay_diff_smooth, INTFLOAT (*power)[32])
{
  int nL = 0;
  IACA_START for (n = n0; n < nL; n++)
    {
      int decayed_peak;
      decayed_peak =
	(int) (((int64_t) peak_decay_factor * peak_decay_nrg[i] +
		0x40000000) >> 31);
      peak_decay_nrg[i] =
	((decayed_peak) > (power[i][n]) ? (decayed_peak) : (power[i][n]));
      power_smooth[i] += (power[i][n] + 2LL - power_smooth[i]) >> 2;
      peak_decay_diff_smooth[i] +=
	(peak_decay_nrg[i] + 2LL - power[i][n] -
	 peak_decay_diff_smooth[i]) >> 2;
      if (peak_decay_diff_smooth[i])
	{
	  transient_gain[i][n] =
	    ((power_smooth[i] * 43691LL / peak_decay_diff_smooth[i]) >
	     (1 << 16) ? (1 << 16) : (power_smooth[i] * 43691LL /
				      peak_decay_diff_smooth[i]));
	}
      else
	transient_gain[i][n] = 1 << 16;
     } IACA_END
}

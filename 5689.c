#include <stdint.h>
#include <stdio.h>






int
fn (float *peak_decay_nrg, int i, float *power_smooth,
    float (*transient_gain)[32], int n0, int n, float (*power)[32],
    float *peak_decay_diff_smooth)
{
  const float a_smooth = 0.25f;
  const float transient_impact = 1.5f;
  const float peak_decay_factor = 0.76592833836465f;
  int nL = 0;
  for (n = n0; n < nL; n++)
    {
      float decayed_peak = peak_decay_factor * peak_decay_nrg[i];
      float denom;
      peak_decay_nrg[i] =
	((decayed_peak) > (power[i][n]) ? (decayed_peak) : (power[i][n]));
      power_smooth[i] += a_smooth * (power[i][n] - power_smooth[i]);
      peak_decay_diff_smooth[i] +=
	a_smooth * (peak_decay_nrg[i] - power[i][n] -
		    peak_decay_diff_smooth[i]);
      denom = transient_impact * peak_decay_diff_smooth[i];
      transient_gain[i][n] =
	(denom > power_smooth[i]) ? power_smooth[i] / denom : 1.0f;
}}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef SoftFloat;

int
fn (SoftFloat (*q_temp)[48], const int h_SL, const int idx1, int m,
    SoftFloat * q_filt, SoftFloat * g_filt, SoftFloat (*g_temp)[48], int j,
    const SoftFloat h_smooth[5])
{
  for (j = 0; j <= h_SL; j++)
    {
      g_filt[m] =
	av_add_sf (g_filt[m], av_mul_sf (g_temp[idx1 - j][m], h_smooth[j]));
      q_filt[m] =
	av_add_sf (q_filt[m], av_mul_sf (q_temp[idx1 - j][m], h_smooth[j]));
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef SoftFloat;

int
fn (const SoftFloat h_smooth[5], SoftFloat (*q_temp)[48], const int h_SL,
    int m, SoftFloat * q_filt, int j, SoftFloat * g_filt,
    SoftFloat (*g_temp)[48], const int idx1)
{
  for (j = 0; j <= h_SL; j++)
    {
      g_filt[m] =
	av_add_sf (g_filt[m], av_mul_sf (g_temp[idx1 - j][m], h_smooth[j]));
      q_filt[m] =
	av_add_sf (q_filt[m], av_mul_sf (q_temp[idx1 - j][m], h_smooth[j]));
    }
}

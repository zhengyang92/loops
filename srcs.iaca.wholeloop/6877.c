#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const float *s_m, float phi_sign0, const float ff_sbr_noise_table[][2],
    const float *q_filt, int noise, float phi_sign1, float (*Y)[2], int m,
    int m_max)
{
  IACA_START for (m = 0; m < m_max; m++)
    {
      float y0 = Y[m][0];
      float y1 = Y[m][1];
      noise = (noise + 1) & 0x1ff;
      if (s_m[m])
	{
	  y0 += s_m[m] * phi_sign0;
	  y1 += s_m[m] * phi_sign1;
	}
      else
	{
	  y0 += q_filt[m] * ff_sbr_noise_table[noise][0];
	  y1 += q_filt[m] * ff_sbr_noise_table[noise][1];
	}
      Y[m][0] = y0;
      Y[m][1] = y1;
      phi_sign1 = -phi_sign1;
     } IACA_END
}

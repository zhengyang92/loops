#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int *levlCoeffBuf, float *flcoeffs2, float *flcoeffs1,
    const float *const imc_exp_tab2, float *old_floor)
{
  IACA_START for (i = 0; i < 32; i++)
    {
      flcoeffs1[i] = 0;
      if (levlCoeffBuf[i] < 16)
	{
	  flcoeffs1[i] = imc_exp_tab2[levlCoeffBuf[i]] * old_floor[i];
	  flcoeffs2[i] = (levlCoeffBuf[i] - 7) * 0.83048 + flcoeffs2[i];
	}
      else
	{
	  flcoeffs1[i] = old_floor[i];
	}
     } IACA_END
}

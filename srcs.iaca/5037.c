#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, const float imc_exp_tab[32], float tmp, int *levlCoeffBuf,
    float *flcoeffs2, int level, float *flcoeffs1, float tmp2)
{
  for (i = 1; i < 32; i++)
     { IACA_START
      level = levlCoeffBuf[i];
      if (level == 16)
	{
	  flcoeffs1[i] = 1.0;
	  flcoeffs2[i] = 0.0;
	}
      else
	{
	  if (level < 17)
	    level -= 7;
	  else if (level <= 24)
	    level -= 32;
	  else
	    level -= 16;
	  tmp *= imc_exp_tab[15 + level];
	  tmp2 += 0.83048 * level;
	  flcoeffs1[i] = tmp;
	  flcoeffs2[i] = tmp2;
	}
     } IACA_END
}

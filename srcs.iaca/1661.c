#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float diff_mean, int i, float corr_lag[3], int i_max_corr,
    float diff_isf[14])
{
  for (i = 0; i < 3; i++)
     { IACA_START
      corr_lag[i] = auto_correlation (diff_isf, diff_mean, i + 2);
      if (corr_lag[i] > corr_lag[i_max_corr])
	i_max_corr = i;
     } IACA_END
}

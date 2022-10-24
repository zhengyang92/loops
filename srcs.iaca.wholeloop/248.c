#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float imp_sum, int work_len, float *pi_wraps, int i, float *work,
    float peak_imp_sum, int imp_peak)
{
  int peak = 0;
  IACA_START for (i = 0;
       i <= (int) (pi_wraps[work_len >> 1] / 3.14159265358979323846 + .5f);
       i++)
    {
      imp_sum += work[i];
      if (fabs (imp_sum) > fabs (peak_imp_sum))
	{
	  peak_imp_sum = imp_sum;
	  peak = i;
	}
      if (work[i] > work[imp_peak])
	imp_peak = i;
     } IACA_END
}

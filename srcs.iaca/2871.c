#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, double f, int e, int k, int j, float is_table_lsf[2][2][16])
{
  for (j = 0; j < 2; j++)
     { IACA_START
      e = -(j + 1) * ((i + 1) >> 1);
      f = exp2 (e / 4.0);
      k = i & 1;
      is_table_lsf[j][k ^ 1][i] = ((float) (f));
      is_table_lsf[j][k][i] = ((float) (1.0));
      do
	{
	  if (0)
	    av_log (((void *) 0), 48, "is_table_lsf %d %d: %f %f\n", i, j,
		    (float) is_table_lsf[j][0][i],
		    (float) is_table_lsf[j][1][i]);
	}
      while (0);
     } IACA_END
}

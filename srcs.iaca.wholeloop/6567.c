#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, double f, int e, int k, int j, int is_table_lsf[2][2][16])
{
  IACA_START for (j = 0; j < 2; j++)
    {
      e = -(j + 1) * ((i + 1) >> 1);
      f = pow (2.0, e / 4.0);
      k = i & 1;
      is_table_lsf[j][k ^ 1][i] = ((int) ((f) * (1 << 23) + 0.5));
      is_table_lsf[j][k][i] = ((int) ((1.0) * (1 << 23) + 0.5));
      do
	{
	}
      while (0);
     } IACA_END
}

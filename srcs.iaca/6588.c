#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, double f, int e, int k, int j, float is_table_lsf[2][2][16])
{
  for (j = 0; j < 2; j++)
    {
      e = -(j + 1) * ((i + 1) >> 1);
      f = pow (2.0, e / 4.0);
      k = i & 1;
      is_table_lsf[j][k ^ 1][i] = ((float) (f));
      is_table_lsf[j][k][i] = ((float) (1.0));
      do
	{
	}
      while (0);
    }
}

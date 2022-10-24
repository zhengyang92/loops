#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int nb_errors, double *interpolated, double *is, double *enabled,
    int *index, int j, double *dst)
{
  IACA_START for (j = 0; j < nb_errors; j++)
    {
      if (enabled[index[j]])
	{
	  dst[index[j]] = interpolated[j];
	  is[index[j]] = 1;
	}
     } IACA_END
}

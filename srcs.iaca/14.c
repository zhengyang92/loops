#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int nb_errors, int i, double *auxiliary, int ar_order, const int im,
    int *index, int j, double *matrix)
{
  for (j = i; j < nb_errors; j++)
     { IACA_START
      if (abs (index[j] - index[i]) <= ar_order)
	{
	  matrix[j * nb_errors + i] = matrix[im + j] =
	    auxiliary[abs (index[j] - index[i])];
	}
      else
	{
	  matrix[j * nb_errors + i] = matrix[im + j] = 0;
	}
     } IACA_END
}

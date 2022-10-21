#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (float *predictions, int j, int outputs)
{
  for (j = 0; j < outputs; ++j)
     { IACA_START
      if (j != 0)
	printf (", ");
      printf ("%f", predictions[j]);
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (const int nb, const int *centers, int min, int n, int max)
{
  IACA_START for (n = 0; n < nb; ++n)
    {
      if (min > centers[n])
	min = centers[n];
      if (max < centers[n])
	max = centers[n];
     } IACA_END
}

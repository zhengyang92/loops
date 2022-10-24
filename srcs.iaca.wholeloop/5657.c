#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *quants, const int dim, int off, int j, const int range)
{
  int curidx = 0;
  IACA_START for (j = 0; j < dim; j++)
    {
      curidx *= range;
      curidx += quants[j] + off;
     } IACA_END
}

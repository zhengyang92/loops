#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (double *tab, int tap_count, int i, float *filter)
{
  IACA_START for (i = 0; i < tap_count; i++)
    {
      filter[i] = tab[i];
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int tap_count, double *tab, double *filter, int i)
{
  for (i = 0; i < tap_count; i++)
     { IACA_START
      filter[i] = tab[i];
     } IACA_END
}

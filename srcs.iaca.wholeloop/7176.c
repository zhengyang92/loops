#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int tap_count, double *tab, double *filter, int i)
{
  IACA_START for (i = 0; i < tap_count; i++)
    {
      filter[i] = tab[i];
     } IACA_END
}

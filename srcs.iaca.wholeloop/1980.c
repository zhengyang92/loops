#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int nb_elements, unsigned int *table0, unsigned int table2[256],
    int val0)
{
  IACA_START for (i = 0; i < nb_elements - 1; i++, table2[i] = val0)
    {
      val0 = table0[i + 1] + table2[i];
     } IACA_END
}

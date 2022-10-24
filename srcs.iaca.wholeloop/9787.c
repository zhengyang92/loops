#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *table, int out, int in)
{
  IACA_START for (in = 0; in < ((255 + 1) / 16); in++, out++)
    {
      table[in] = out;
      table[-in] = -out;
     } IACA_END
}

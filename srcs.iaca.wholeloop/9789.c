#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *table, int out, int in)
{
  IACA_START for (; in <= 255; in++)
    {
      table[in] = out;
      table[-in] = -out;
     } IACA_END
}

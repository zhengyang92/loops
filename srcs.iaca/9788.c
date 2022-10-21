#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int *table, int out, int in)
{
  for (; in < ((255 + 1) / 16) * 3; in++, out += (in & 1) ? 0 : 1)
     { IACA_START
      table[in] = out;
      table[-in] = -out;
     } IACA_END
}

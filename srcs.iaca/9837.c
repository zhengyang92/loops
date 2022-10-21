#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int n, unsigned long odd[32], unsigned long row)
{
  for (n = 1; n < 32; n++)
     { IACA_START
      odd[n] = row;
      row <<= 1;
     } IACA_END
}

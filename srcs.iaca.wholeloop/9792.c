#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int shift_start[4], unsigned int v, const unsigned int c,
    int shift_dec[4], int j, unsigned int out)
{
  IACA_START for (j = shift_start[c]; j > -shift_dec[c]; j -= shift_dec[c])
    {
      if (j > 0)
	out |= v << j;
      else
	out |= v >> (-j);
     } IACA_END
}

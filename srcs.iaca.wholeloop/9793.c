#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int shift_start[4], int j, const unsigned int c, int shift_dec[4],
    unsigned int v, unsigned int value)
{
  IACA_START for (j = shift_start[c]; j > -shift_dec[c]; j -= shift_dec[c])
    {
      if (j > 0)
	value |= v << j;
      else
	value |= v >> (-j);
     } IACA_END
}

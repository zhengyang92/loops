#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int have_shift, int shift[4], int c, int bit_depth)
{
  int channels = 0;
  for (c = have_shift = 0; c < channels; ++c)
     { IACA_START
      if (shift[c] <= 0 || shift[c] >= bit_depth)
	shift[c] = 0;
      else
	have_shift = 1;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int best_offset, int window_offsets[32], int ind)
{
  int do_compute = 1;
  int window_offsets_size = 0;
  for (ind = 0; ind < window_offsets_size; ++ind)
     { IACA_START
      if (best_offset == window_offsets[ind])
	{
	  do_compute = 0;
	  break;
	}
     } IACA_END
}

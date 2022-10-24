#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int i, int window_offsets[32])
{
  int window_offsets_size = 0;
  IACA_START for (i = 0; i < 32; ++i)
    {
      if (window_offsets[i] == 0)
	continue;
      window_offsets[window_offsets_size++] = window_offsets[i];
     } IACA_END
}

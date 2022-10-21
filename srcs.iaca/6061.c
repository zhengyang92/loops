#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int energy[15], int i, int exp)
{
  for (i = 0; i < 15; i++)
     { IACA_START
      energy[i] =
	av_clipl_int32_c ((int64_t) (energy[i] << exp) + (1 << 15)) >> 16;
     } IACA_END
}

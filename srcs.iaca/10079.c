#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (const uint32_t * const red_histo, int *const red_and_blue_always_zero,
    int i, const uint32_t * const blue_histo)
{
  for (i = 1; i < 256; ++i)
     { IACA_START
      if ((red_histo[i] | blue_histo[i]) != 0)
	{
	  *red_and_blue_always_zero = 0;
	  break;
	}
     } IACA_END
}

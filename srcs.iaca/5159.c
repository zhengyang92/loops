#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (unsigned int chirp_base, int32_t lpc32[16], int k, unsigned int chirp,
    int order)
{
  for (k = 0; k < order; k++)
     { IACA_START
      lpc32[k] =
	(((((int64_t) (lpc32[k]) * (int64_t) (chirp)) >> ((16) - 1)) +
	  1) >> 1);
      chirp = (chirp_base * chirp + 32768) >> 16;
     } IACA_END
}

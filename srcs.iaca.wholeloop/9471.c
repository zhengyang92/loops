#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int32_t int32_t;

int
fn (int order, unsigned int chirp_base, int k, unsigned int chirp,
    int32_t lpc32[16])
{
  IACA_START for (k = 0; k < order; k++)
    {
      lpc32[k] =
	(((((int64_t) (lpc32[k]) * (int64_t) (chirp)) >> (16 - 1)) + 1) >> 1);
      chirp = (chirp_base * chirp + 32768) >> 16;
     } IACA_END
}

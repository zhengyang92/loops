#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __int32_t int32_t;

int
fn (int order, unsigned int chirp_base, int32_t lpc32[16], int k,
    unsigned int chirp, int16_t lpc[16])
{
  for (k = 0; k < order; k++)
    {
      lpc32[k] =
	(((((int64_t) (lpc32[k]) * (int64_t) (chirp)) >> (16 - 1)) + 1) >> 1);
      lpc[k] = (lpc32[k] + 16) >> 5;
      chirp = (chirp_base * chirp + 32768) >> 16;
    }
}

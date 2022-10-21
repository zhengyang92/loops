#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t * const row, int i, const uint8_t * const in,
    const uint8_t * const top, int length)
{
  for (; i < length; ++i)
     { IACA_START
      row[i] =
	in[i] + GradientPredictor_SSE2 (row[i - 1], top[i], top[i - 1]);
     } IACA_END
}

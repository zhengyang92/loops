#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, uint8_t ve[11], uint8_t vo[11], int i)
{
  for (i = 0; i < 8 / 2 - 2; i++)
     { IACA_START
      vo[i] =
	(left[i * 2 + 3] + left[i * 2 + 2] * 2 + left[i * 2 + 1] + 2) >> 2;
      ve[i] =
	(left[i * 2 + 4] + left[i * 2 + 3] * 2 + left[i * 2 + 2] + 2) >> 2;
     } IACA_END
}

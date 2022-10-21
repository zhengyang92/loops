#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t vo[23], const uint16_t * left, uint16_t ve[23], int i)
{
  for (i = 0; i < 16 / 2 - 2; i++)
     { IACA_START
      vo[i] =
	(left[i * 2 + 3] + left[i * 2 + 2] * 2 + left[i * 2 + 1] + 2) >> 2;
      ve[i] =
	(left[i * 2 + 4] + left[i * 2 + 3] * 2 + left[i * 2 + 2] + 2) >> 2;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, uint8_t ve[47], int i, uint8_t vo[47])
{
  for (i = 0; i < 32 / 2 - 2; i++)
    {
      vo[i] =
	(left[32 - 4 - i * 2] + left[32 - 3 - i * 2] * 2 +
	 left[32 - 2 - i * 2] + 2) >> 2;
      ve[i] =
	(left[32 - 5 - i * 2] + left[32 - 4 - i * 2] * 2 +
	 left[32 - 3 - i * 2] + 2) >> 2;
    }
}

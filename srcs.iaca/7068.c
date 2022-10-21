#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, const uint8_t * top, int i, uint8_t v[46])
{
  for (i = 0; i < 16 - 2; i++)
     { IACA_START
      v[i * 2] = (left[16 - 2 - i] + left[16 - 1 - i] + 1) >> 1;
      v[i * 2 + 1] =
	(left[16 - 3 - i] + left[16 - 2 - i] * 2 + left[16 - 1 - i] + 2) >> 2;
      v[16 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
     } IACA_END
}

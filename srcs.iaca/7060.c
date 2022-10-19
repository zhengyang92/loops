#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, const uint8_t * top, uint8_t v[63], int i)
{
  for (i = 0; i < 32 - 2; i++)
    {
      v[i] =
	(left[32 - 1 - i] + left[32 - 2 - i] * 2 + left[32 - 3 - i] + 2) >> 2;
      v[32 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}

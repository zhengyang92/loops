#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, int i, uint8_t v[94], const uint8_t * left)
{
  for (i = 0; i < 32 - 2; i++)
    {
      v[i * 2] = (left[32 - 2 - i] + left[32 - 1 - i] + 1) >> 1;
      v[i * 2 + 1] =
	(left[32 - 3 - i] + left[32 - 2 - i] * 2 + left[32 - 1 - i] + 2) >> 2;
      v[32 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
}

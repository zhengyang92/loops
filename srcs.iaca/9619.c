#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, const uint8_t * left, int i, uint8_t v[31])
{
  for (i = 0; i < 16 - 2; i++)
    {
      v[i] =
	(left[16 - 1 - i] + left[16 - 2 - i] * 2 + left[16 - 3 - i] + 2) >> 2;
      v[16 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}

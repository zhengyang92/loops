#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * top, const uint8_t * left, int i, uint8_t v[15])
{
  for (i = 0; i < 8 - 2; i++)
    {
      v[i] =
	(left[8 - 1 - i] + left[8 - 2 - i] * 2 + left[8 - 3 - i] + 2) >> 2;
      v[8 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    }
}

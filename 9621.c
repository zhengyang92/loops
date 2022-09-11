#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * left, uint8_t vo[11], int i, uint8_t ve[11])
{
  for (i = 0; i < 8 / 2 - 2; i++)
    {
      vo[i] =
	(left[8 - 4 - i * 2] + left[8 - 3 - i * 2] * 2 + left[8 - 2 - i * 2] +
	 2) >> 2;
      ve[i] =
	(left[8 - 5 - i * 2] + left[8 - 4 - i * 2] * 2 + left[8 - 3 - i * 2] +
	 2) >> 2;
    }
}

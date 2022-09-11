#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t vo[23], const uint8_t * left, int i, uint8_t ve[23])
{
  for (i = 0; i < 16 / 2 - 2; i++)
    {
      vo[i] =
	(left[16 - 4 - i * 2] + left[16 - 3 - i * 2] * 2 +
	 left[16 - 2 - i * 2] + 2) >> 2;
      ve[i] =
	(left[16 - 5 - i * 2] + left[16 - 4 - i * 2] * 2 +
	 left[16 - 3 - i * 2] + 2) >> 2;
    }
}

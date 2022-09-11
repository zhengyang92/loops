#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (const int *qmat, int16_t * block, const uint8_t * scantable, int i)
{
  int last_non_zero = 0;
  for (i = 1; i < 64; ++i)
    {
      int j = scantable[i];
      int sign = (block[j] >> 8 * sizeof (block[j]) - 1);
      int level = (block[j] ^ sign) - sign;
      level = level * qmat[j] >> 18;
      block[j] = (level ^ sign) - sign;
      if (level)
	last_non_zero = i;
    }
}

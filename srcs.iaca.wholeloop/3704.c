#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int m, uint8_t * const src, int k, int j, int l)
{
  IACA_START for (m = j - 2; m <= j; m++)
    {
      if (l <= 0 || l >= i && m == j)
	continue;
      if (l <= 48 && m > 0)
	k = 2 * k + src[l + m * 48];
     } IACA_END
}

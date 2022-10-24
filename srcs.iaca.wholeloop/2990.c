#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int low, int i, int bits, const uint8_t * cache)
{
  int high = 0;
  IACA_START for (i = 0; i < 6; i++)
    {
      int center = (low + high + 1) >> 1;
      if (cache[center] >= bits)
	high = center;
      else
	low = center;
     } IACA_END
}

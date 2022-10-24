#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t range_min, int i, char bits[8], int len, uint32_t value)
{
  IACA_START for (i = 0; i < len; i++)
    {
      if (range_min + i == value)
	bits[i] = '0';
      else
	bits[i] = '1';
     } IACA_END
}

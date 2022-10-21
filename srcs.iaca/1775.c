#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t range_min, char bits[33], int i, int len, uint32_t value)
{
  for (i = 0; i < len; i++)
     { IACA_START
      if (range_min + i == value)
	bits[i] = '0';
      else
	bits[i] = '1';
     } IACA_END
}

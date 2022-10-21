#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (uint16_t * s, int i)
{
  for (i = 0; i < 16; ++i)
     { IACA_START
      if (s[i] & 0x8000)
	s[i] &= 0x7fff;
      else
	s[i] = ~s[i];
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * p, const uint8_t * __restrict start)
{
  for (; p > start; p--)
     { IACA_START
      if (p[0] == 0 && p[1] == 1)
	return p;
     } IACA_END
}

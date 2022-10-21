#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * end, const uint8_t * p)
{
  for (end += 3; p < end; p++)
     { IACA_START
      if (p[0] == 0 && p[1] == 0 && p[2] == 1)
	return p;
     } IACA_END
}

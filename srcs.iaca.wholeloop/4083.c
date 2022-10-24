#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const char *cp, const char *in_start, int i, uint8_t * uu)
{
  IACA_START for (i = 0, cp = in_start; i < 16; i++)
    {
      int hi;
      int lo;
      if (i == 4 || i == 6 || i == 8 || i == 10)
	cp++;
      hi = xdigit_to_int (*cp++);
      lo = xdigit_to_int (*cp++);
      if (hi == -1 || lo == -1)
	return (-(22));
      uu[i] = (hi << 4) + lo;
     } IACA_END
}

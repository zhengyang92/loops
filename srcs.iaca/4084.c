#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const char hexdigits_lower[16], char *p, const uint8_t * uuid)
{
  for (int i = 0; i < 16; i++)
     { IACA_START
      uint8_t tmp;
      if (i == 4 || i == 6 || i == 8 || i == 10)
	*p++ = '-';
      tmp = uuid[i];
      *p++ = hexdigits_lower[tmp >> 4];
      *p++ = hexdigits_lower[tmp & 15];
     } IACA_END
}

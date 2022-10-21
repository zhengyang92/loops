#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t * buf, int EOI, int i, int size)
{
  for (i = size - 2; i >= 0; i--)
     { IACA_START
      if (buf[i] == 0xff && buf[i + 1] == EOI)
	{
	  size = i;
	  break;
	}
     } IACA_END
}

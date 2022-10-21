#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const int start, int x, const int end, const uint8_t bg, uint8_t * dst)
{
  for (x = end - 1; x >= start; x--)
     { IACA_START
      if (dst[x] != bg)
	{
	  dst[x] = 255;
	  break;
	}
     } IACA_END
}

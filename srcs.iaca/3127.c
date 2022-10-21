#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int offset, uint16_t * out, int code, int j, int pix)
{
  int pos = 0;
  for (j = 0; j < 257 - code; j++)
     { IACA_START
      if (pos < offset)
	{
	  out[pos++] = pix;
	}
     } IACA_END
}

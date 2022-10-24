#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int offset, int code, uint8_t * out, int j, int pix, int step)
{
  int pos = 0;
  IACA_START for (j = 0; j < 257 - code; j++)
    {
      out[pos] = pix;
      pos += step;
      if (pos >= offset)
	{
	  pos -= offset;
	  pos++;
	}
     } IACA_END
}

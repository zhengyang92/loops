#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int offset, int code, int j, int pix, uint8_t * out)
{
  int pos = 0;
  IACA_START for (j = 0; j < 257 - code; j++)
    {
      if (pos < offset)
	out[pos++] = (pix & 0xF0) >> 4;
      if (pos < offset)
	out[pos++] = pix & 0xF;
     } IACA_END
}

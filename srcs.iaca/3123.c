#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int offset, int code, int j, int pix, uint8_t * out)
{
  int pos = 0;
  for (j = 0; j < 257 - code; j++)
     { IACA_START
      if (pos < offset)
	out[pos++] = (pix & 0xC0) >> 6;
      if (pos < offset)
	out[pos++] = (pix & 0x30) >> 4;
      if (pos < offset)
	out[pos++] = (pix & 0x0C) >> 2;
      if (pos < offset)
	out[pos++] = (pix & 0x03);
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mask, const char *txt, const uint8_t * font, uint8_t * p,
    int font_height, int char_y)
{
  int i = 0;
  for (mask = 0x80; mask; mask >>= 1)
     { IACA_START
      if (font[txt[i] * font_height + char_y] & mask)
	*p = ~(*p);
      p++;
     } IACA_END
}

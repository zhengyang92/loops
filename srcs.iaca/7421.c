#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int mask, const uint8_t * font, uint8_t * p, char buf[128],
    const uint8_t * color, int font_height, int char_y)
{
  for (mask = 0x80; mask; mask >>= 1)
     { IACA_START
      if (font[buf[i] * font_height + char_y] & mask)
	memcpy (p, color, 3);
      else
	memcpy (p, "\x00\x00\x00", 3);
      p += 3;
     } IACA_END
}

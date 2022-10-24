#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int mask, uint8_t * p, char buf[128], const uint8_t * font,
    const uint8_t * color, int font_height, int char_y)
{
  IACA_START for (mask = 0x80; mask; mask >>= 1)
    {
      if (font[buf[i] * font_height + char_y] & mask)
	memcpy (p, color, 3);
      else
	memcpy (p, "\x00\x00\x00", 3);
      p += 3;
     } IACA_END
}

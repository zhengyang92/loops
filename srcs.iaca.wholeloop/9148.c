#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int fg, int mask, int ch, const uint8_t * font, int bg, int font_height,
    uint8_t * dst, int char_y)
{
  IACA_START for (mask = 0x80; mask; mask >>= 1)
    {
      *dst++ = font[ch * font_height + char_y] & mask ? fg : bg;
     } IACA_END
}

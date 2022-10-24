#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int v, int mask, const char *txt, uint8_t * p, float o1,
    const uint8_t * font, int font_height, float o2, int char_y)
{
  IACA_START for (mask = 0x80; mask; mask >>= 1)
    {
      if (font[txt[i] * font_height + char_y] & mask)
	p[0] = p[0] * o2 + v * o1;
      p++;
     } IACA_END
}

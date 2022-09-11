#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, int mask, const char *txt, uint8_t * color, const uint8_t * font,
    uint8_t * p, int font_height, int char_y)
{
  for (mask = 0x80; mask; mask >>= 1)
    {
      if (font[txt[i] * font_height + char_y] & mask)
	{
	  p[0] = color[0];
	  p[1] = color[1];
	  p[2] = color[2];
	}
      p += 4;
    }
}

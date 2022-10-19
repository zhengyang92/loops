#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int v, const uint8_t avpriv_vga16_font[4096], int mask, int u,
    uint8_t * p, const char *str)
{
  for (mask = 0x80; mask; mask >>= 1, p += 4)
    {
      if (mask & avpriv_vga16_font[str[u] * 16 + v])
	p[3] = 255;
      else
	p[3] = 0;
    }
}

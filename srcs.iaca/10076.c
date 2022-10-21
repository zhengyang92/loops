#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t * palette, int i, uint32_t predict, int num_colors,
    uint8_t sign_found)
{
  for (i = 0; i < num_colors; ++i)
     { IACA_START
      const uint32_t diff = VP8LSubPixels (palette[i], predict);
      const uint8_t rd = (diff >> 16) & 0xff;
      const uint8_t gd = (diff >> 8) & 0xff;
      const uint8_t bd = (diff >> 0) & 0xff;
      if (rd != 0x00)
	{
	  sign_found |= (rd < 0x80) ? 1 : 2;
	}
      if (gd != 0x00)
	{
	  sign_found |= (gd < 0x80) ? 8 : 16;
	}
      if (bd != 0x00)
	{
	  sign_found |= (bd < 0x80) ? 64 : 128;
	}
      predict = palette[i];
     } IACA_END
}

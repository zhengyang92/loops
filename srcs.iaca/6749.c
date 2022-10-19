#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int mask, int width, int dsp_mask, int x, uint8_t * d, int bpp, int j,
    const uint8_t * s)
{
  for (x = 0; x < width; x++)
    {
      j = x & 7;
      if ((dsp_mask << j) & 0x80)
	{
	  *(uint32_t *) d = (s[3] << 24) | (s[0] << 16) | (s[1] << 8) | s[2];
	}
      d += bpp;
      if ((mask << j) & 0x80)
	s += bpp;
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int palette_size, int width, int x, uint32_t prev_pix, uint32_t prev_idx,
    const uint32_t * src, const uint32_t * palette, uint8_t * const tmp_row)
{
  IACA_START for (x = 0; x < width; ++x)
    {
      const uint32_t pix = src[x];
      if (pix != prev_pix)
	{
	  prev_idx = SearchColorGreedy (palette, palette_size, pix);
	  prev_pix = pix;
	}
      tmp_row[x] = prev_idx;
     } IACA_END
}

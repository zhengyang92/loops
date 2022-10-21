#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (int palette_size, uint32_t idx_map[256], int width, int x,
    uint32_t palette_sorted[256], uint32_t prev_pix, uint32_t prev_idx,
    const uint32_t * src, uint8_t * const tmp_row)
{
  for (x = 0; x < width; ++x)
     { IACA_START
      const uint32_t pix = src[x];
      if (pix != prev_pix)
	{
	  prev_idx =
	    idx_map[SearchColorNoIdx (palette_sorted, pix, palette_size)];
	  prev_pix = pix;
	}
      tmp_row[x] = prev_idx;
     } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (uint32_t * palette, int i, uint32_t predict, int num_colors, int k,
    int best_ix, uint32_t best_score)
{
  IACA_START for (k = i; k < num_colors; ++k)
    {
      const uint32_t cur_score = PaletteColorDistance (palette[k], predict);
      if (best_score > cur_score)
	{
	  best_score = cur_score;
	  best_ix = k;
	}
     } IACA_END
}

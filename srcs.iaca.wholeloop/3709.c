#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef GetBitContext;
typedef __uint8_t uint8_t;

int
fn (uint8_t * bitmap, int w, int x, const uint8_t ff_log2_tab[256],
    GetBitContext gb)
{
  IACA_START for (x = 0; x < w;)
    {
      int log2 = ff_log2_tab[show_bits (&gb, 8)];
      int run = get_bits (&gb, 14 - 4 * (log2 >> 1));
      int color = get_bits (&gb, 2);
      run = ((run) > (w - x) ? (w - x) : (run));
      if (!run)
	run = w - x;
      memset (bitmap, color, run);
      bitmap += run;
      x += run;
     } IACA_END
}

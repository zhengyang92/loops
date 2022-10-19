#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef BitstreamContext;
typedef __uint8_t uint8_t;

int
fn (uint8_t * bitmap, int w, int x, const uint8_t ff_log2_tab[256],
    BitstreamContext bc)
{
  for (x = 0; x < w;)
    {
      int log2 = ff_log2_tab[bitstream_peek (&bc, 8)];
      int run = bitstream_read (&bc, 14 - 4 * (log2 >> 1));
      int color = bitstream_read (&bc, 2);
      run = ((run) > (w - x) ? (w - x) : (run));
      if (!run)
	run = w - x;
      memset (bitmap, color, run);
      bitmap += run;
      x += run;
    }
}

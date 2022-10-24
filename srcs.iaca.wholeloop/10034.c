#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VP8LHistogram;

int
fn (VP8LHistogram ** const out_histo, int i, const int out_size)
{
  IACA_START for (i = 0; i < out_size; ++i)
    {
      HistogramClear (out_histo[i]);
     } IACA_END
}

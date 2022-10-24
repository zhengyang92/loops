#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VP8LHistogram;

int
fn (int idx, VP8LHistogram ** const histograms)
{
  int size = 0;
  IACA_START for (idx = 0; idx < size; ++idx)
    {
      UpdateHistogramCost (histograms[idx]);
     } IACA_END
}

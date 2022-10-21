#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VP8LHistogram;

int
fn (int idx, VP8LHistogram ** const histograms)
{
  int size = 0;
  for (idx = 0; idx < size; ++idx)
     { IACA_START
      UpdateHistogramCost (histograms[idx]);
     } IACA_END
}

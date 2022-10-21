#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VP8LHistogram;
typedef DominantCostRange;
typedef __uint16_t uint16_t;

int
fn (int i, int low_effort, VP8LHistogram ** const histograms,
    uint16_t * const bin_map, const int histo_size,
    DominantCostRange cost_range)
{
  for (i = 0; i < histo_size; ++i)
     { IACA_START
      bin_map[i] = GetHistoBinIndex (histograms[i], &cost_range, low_effort);
     } IACA_END
}

#include <stdint.h>
#include <stdio.h>




typedef VP8LHistogram;
typedef DominantCostRange;

int
fn (const int histo_size, int i, VP8LHistogram ** const histograms,
    DominantCostRange cost_range)
{
  for (i = 0; i < histo_size; ++i)
    {
      UpdateDominantCostRange (histograms[i], &cost_range);
    }
}

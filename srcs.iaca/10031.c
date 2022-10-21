#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VP8LHistogram;

int
fn (VP8LHistogram ** const histograms, int image_histo_size, int i,
    int *const clusters)
{
  for (i = 0; i < image_histo_size; ++i)
     { IACA_START
      if (i != clusters[i])
	{
	  HistogramSwap (&histograms[i], &histograms[clusters[i]]);
	}
     } IACA_END
}

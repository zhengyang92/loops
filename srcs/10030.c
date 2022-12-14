#include <stdint.h>
#include <stdio.h>




typedef HistoQueue;
typedef VP8LHistogram;

int
fn (int i, HistoQueue histo_queue, int image_histo_size, int *const clusters,
    VP8LHistogram ** const histograms, const int idx1)
{
  for (i = 0; i < image_histo_size; ++i)
    {
      if (clusters[i] != idx1)
	{
	  HistoQueuePush (&histo_queue, histograms, idx1, clusters[i], 0.);
	}
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef VP8LHistogram;

int
fn (VP8LHistogram ** const orig_histograms, int i, const int histo_size,
    VP8LHistogram ** const histograms)
{
  for (i = 0; i < histo_size; ++i)
    {
      VP8LHistogram *const histo = orig_histograms[i];
      UpdateHistogramCost (histo);
      HistogramCopy (histo, histograms[i]);
}}

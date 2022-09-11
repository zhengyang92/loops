#include <stdint.h>
#include <stdio.h>




typedef VP8LHistogram;

int
fn (VP8LHistogram ** const out_histo, int i, int k, const int out_size,
    VP8LHistogram ** const in_histo)
{
  double best_bits = 1.e38;
  int best_out = 0;
  for (k = 0; k < out_size; ++k)
    {
      const double cur_bits =
	HistogramAddThresh (out_histo[k], in_histo[i], best_bits);
      if (k == 0 || cur_bits < best_bits)
	{
	  best_bits = cur_bits;
	  best_out = k;
	}
    }
}

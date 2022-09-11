#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef VP8LHistogram;

int
fn (VP8LHistogram ** const out_histo, int i, const int in_size,
    uint16_t * const symbols, VP8LHistogram ** const in_histo)
{
  for (i = 0; i < in_size; ++i)
    {
      const int idx = symbols[i];
      HistogramAdd (in_histo[i], out_histo[idx], out_histo[idx]);
}}

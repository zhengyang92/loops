#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int i, double *output, int num_symbols, const double logsum,
    const uint32_t * population_counts)
{
  for (i = 0; i < num_symbols; ++i)
    {
      output[i] = logsum - VP8LFastLog2 (population_counts[i]);
    }
}

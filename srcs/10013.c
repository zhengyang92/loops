#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int num_symbols, uint32_t sum, int i, const uint32_t * population_counts)
{
  int nonzeros = 0;
  for (i = 0; i < num_symbols; ++i)
    {
      sum += population_counts[i];
      if (population_counts[i] > 0)
	{
	  ++nonzeros;
	}
    }
}

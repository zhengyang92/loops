#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (uint8_t (*path)[35768], int *idx_table, int band,
    const int16_t ff_nelly_delta_table[32], int best_idx)
{
  for (band = 23 - 1; band >= 0; band--)
    {
      idx_table[band] = path[band][best_idx];
      if (band)
	{
	  best_idx -= ff_nelly_delta_table[path[band][best_idx]];
	}
    }
}

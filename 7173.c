#include <stdint.h>
#include <stdio.h>




typedef __uint64_t uint64_t;

int
fn (uint64_t in_layout, uint64_t out_layout, int i, double matrix[64][64])
{
  for (i = 0; i < 64; i++)
    {
      if (in_layout & out_layout & (1ULL << i))
	matrix[i][i] = 1.0;
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int histogram_size, int max_depth, uint8_t * const bit_depths, int j)
{
  for (j = 1; j < histogram_size; ++j)
    {
      if (max_depth < bit_depths[j])
	{
	  max_depth = bit_depths[j];
	}
    }
}

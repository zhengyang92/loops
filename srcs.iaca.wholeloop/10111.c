#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long unsigned int size_t;
typedef __uint8_t uint8_t;

int
fn (int min_s, int freq[256], const size_t data_size, int num_levels_in,
    uint8_t * const data, size_t n)
{
  int max_s = 255;
  IACA_START for (n = 0; n < data_size; ++n)
    {
      num_levels_in += (freq[data[n]] == 0);
      if (min_s > data[n])
	min_s = data[n];
      if (max_s < data[n])
	max_s = data[n];
      ++freq[data[n]];
     } IACA_END
}

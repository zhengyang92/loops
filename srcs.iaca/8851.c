#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int max_rate_categories[28], const uint8_t expected_bits_table[8],
    int offset, int i, int min_rate_categories[28], int number_of_regions,
    int expected_number_of_code_bits, int *power_categories, int region,
    int *absolute_region_power_index)
{
  for (region = 0; region < number_of_regions; region++)
    {
      i = (offset - absolute_region_power_index[region]) >> 1;
      i = av_clip_uintp2_c (i, 3);
      max_rate_categories[region] = min_rate_categories[region] =
	power_categories[region] = i;
      expected_number_of_code_bits += expected_bits_table[i];
    }
}

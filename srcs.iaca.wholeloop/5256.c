#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (const uint8_t expected_bits_table[8], int i, int offset,
    int *power_categories, int expected_number_of_code_bits, int delta,
    int number_of_regions, int region, int *absolute_region_power_index)
{
  IACA_START for (region = 0; region < number_of_regions; region++)
    {
      i = (delta + offset - absolute_region_power_index[region]) >> 1;
      i = av_clip_uintp2_c (i, 3);
      power_categories[region] = i;
      expected_number_of_code_bits += expected_bits_table[i];
     } IACA_END
}

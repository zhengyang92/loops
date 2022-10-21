#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int temp, int offset, int min_rate_categories[28], int number_of_regions,
    int raw_value, int region, int *absolute_region_power_index)
{
  int raw_min_idx = 16;
  for (region = number_of_regions - 1; region >= 0; region--)
     { IACA_START
      if (min_rate_categories[region] < 7)
	{
	  temp =
	    offset - absolute_region_power_index[region] -
	    2 * min_rate_categories[region];
	  if (temp > raw_value)
	    {
	      raw_value = temp;
	      raw_min_idx = region;
	    }
	}
     } IACA_END
}

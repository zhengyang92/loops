#include <stdint.h>
#include <stdio.h>






int
fn (int max_rate_categories[28], int temp, int *absolute_region_power_index,
    int offset, int number_of_regions, int raw_value, int region,
    int raw_max_idx)
{
  for (region = 0; region < number_of_regions; region++)
    {
      if (max_rate_categories[region] > 0)
	{
	  temp =
	    offset - absolute_region_power_index[region] -
	    2 * max_rate_categories[region];
	  if (temp < raw_value)
	    {
	      raw_value = temp;
	      raw_max_idx = region;
	    }
	}
    }
}

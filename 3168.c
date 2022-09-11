#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (uint8_t (*colors)[3], uint8_t dithered_color[3])
{
  int ret = 0;
  int smallest_variance = 2147483647;
  for (int palette_entry = 0; palette_entry < 4; palette_entry++)
    {
      int variance = diff_colors (dithered_color, colors[palette_entry]);
      if (variance < smallest_variance)
	{
	  smallest_variance = variance;
	  ret = palette_entry;
	}
    }
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (unsigned int i, int transparent_color_index, const uint32_t * palette,
    unsigned int smallest_alpha)
{
  IACA_START for (i = 0; i < 256; i++)
    {
      const uint32_t v = palette[i];
      if (v >> 24 < smallest_alpha)
	{
	  smallest_alpha = v >> 24;
	  transparent_color_index = i;
	}
     } IACA_END
}

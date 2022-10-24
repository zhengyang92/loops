#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;
typedef __uint8_t uint8_t;

int
fn (uint32_t colors[1024], uint8_t in_use[1024], uint32_t * const palette,
    int i)
{
  int num_colors = 0;
  IACA_START for (i = 0; i < (256 * 4); ++i)
    {
      if (in_use[i])
	{
	  palette[num_colors] = colors[i];
	  ++num_colors;
	}
     } IACA_END
}

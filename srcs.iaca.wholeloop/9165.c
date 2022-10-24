#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int i, uint8_t * alpha, int nb_opaque_colors, uint8_t color_used[16],
    uint8_t * colormap)
{
  IACA_START for (i = 0; i < 4; i++)
    {
      if (alpha[i] != 0 && !color_used[colormap[i]])
	{
	  color_used[colormap[i]] = 1;
	  nb_opaque_colors++;
	}
     } IACA_END
}

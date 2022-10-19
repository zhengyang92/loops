#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (uint32_t * rgba_palette, int g, int i, uint8_t * alpha,
    uint32_t subtitle_color, int nb_opaque_colors, uint8_t * colormap,
    int level, const uint8_t level_map[4][4], uint8_t color_used[16], int r,
    int j, int b)
{
  for (i = 0; i < 4; i++)
    {
      if (alpha[i] != 0)
	{
	  if (!color_used[colormap[i]])
	    {
	      level = level_map[nb_opaque_colors - 1][j];
	      r = (((subtitle_color >> 16) & 0xff) * level) >> 8;
	      g = (((subtitle_color >> 8) & 0xff) * level) >> 8;
	      b = (((subtitle_color >> 0) & 0xff) * level) >> 8;
	      rgba_palette[i] =
		b | (g << 8) | (r << 16) | ((alpha[i] * 17U) << 24);
	      color_used[colormap[i]] = (i + 1);
	      j++;
	    }
	  else
	    {
	      rgba_palette[i] =
		(rgba_palette[color_used[colormap[i]] - 1] & 0x00ffffff) |
		((alpha[i] * 17U) << 24);
	    }
	}
    }
}

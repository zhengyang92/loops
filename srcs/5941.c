#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int g, int i, uint32_t subtitle_color, uint8_t * alpha, int j,
    int nb_opaque_colors, int level, uint8_t * colormap, int r,
    uint8_t color_used[16], uint32_t * rgba_palette, int b)
{
  for (i = 0; i < 4; i++)
    {
      if (alpha[i] != 0)
	{
	  if (!color_used[colormap[i]])
	    {
	      level = (0xff * j) / nb_opaque_colors;
	      r = (((subtitle_color >> 16) & 0xff) * level) >> 8;
	      g = (((subtitle_color >> 8) & 0xff) * level) >> 8;
	      b = (((subtitle_color >> 0) & 0xff) * level) >> 8;
	      rgba_palette[i] =
		b | (g << 8) | (r << 16) | ((alpha[i] * 17) << 24);
	      color_used[colormap[i]] = (i + 1);
	      j--;
	    }
	  else
	    {
	      rgba_palette[i] =
		(rgba_palette[color_used[colormap[i]] - 1] & 0x00ffffff) |
		((alpha[i] * 17) << 24);
	    }
	}
    }
}

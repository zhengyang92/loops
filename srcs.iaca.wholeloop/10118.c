#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __uint32_t uint32_t;

int
fn (int x, const int width, uint8_t in_use[1024], uint32_t last_pix,
    const uint32_t * argb, uint32_t colors[1024])
{
  int num_colors = 0;
  IACA_START for (x = 0; x < width; ++x)
    {
      int key;
      if (argb[x] == last_pix)
	{
	  continue;
	}
      last_pix = argb[x];
      key = VP8LHashPix (last_pix, 22);
      while (1)
	{
	  if (!in_use[key])
	    {
	      colors[key] = last_pix;
	      in_use[key] = 1;
	      ++num_colors;
	      if (num_colors > 256)
		{
		  return 256 + 1;
		}
	      break;
	    }
	  else if (colors[key] == last_pix)
	    {
	      break;
	    }
	  else
	    {
	      ++key;
	      key &= ((256 * 4) - 1);
	    }
	}
     } IACA_END
}

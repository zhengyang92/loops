#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint32_t uint32_t;

int
fn (int ix, uint32_t * const argb, int width, const int ix_end,
    int accumulated_blue_histo[256], int accumulated_red_histo[256])
{
  for (; ix < ix_end; ++ix)
    {
      const uint32_t pix = argb[ix];
      if (ix >= 2 && pix == argb[ix - 2] && pix == argb[ix - 1])
	{
	  continue;
	}
      if (ix >= width + 2 && argb[ix - 2] == argb[ix - width - 2]
	  && argb[ix - 1] == argb[ix - width - 1] && pix == argb[ix - width])
	{
	  continue;
	}
      ++accumulated_red_histo[(pix >> 16) & 0xff];
      ++accumulated_blue_histo[(pix >> 0) & 0xff];
    }
}

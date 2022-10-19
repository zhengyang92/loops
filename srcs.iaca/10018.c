#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>






int
fn (int y, int xsize, int x, int window_offsets[32])
{
  for (x = -6; x <= 6; ++x)
    {
      const int offset = y * xsize + x;
      int plane_code;
      if (offset <= 0)
	continue;
      plane_code = VP8LDistanceToPlaneCode (xsize, offset) - 1;
      if (plane_code >= 32)
	continue;
      window_offsets[plane_code] = offset;
    }
}

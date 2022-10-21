#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int y, int w, int dX, int i, int radius, int x, int h, int p2,
    int src_linesize, int sign, int k, const uint8_t * src, int dY, int tmp,
    int j, int p1)
{
  for (k = 0; k < radius; k++)
     { IACA_START
      x = i - k * dX;
      y = j - k * dY;
      p1 = y * src_linesize + x;
      x -= dX;
      y -= dY;
      p2 = y * src_linesize + x;
      if (x < 0 || x >= w || y < 0 || y >= h)
	return 0;
      tmp = (src[p1] - src[p2]) * sign;
      if (tmp <= 0)
	break;
     } IACA_END
}

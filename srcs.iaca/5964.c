#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int bottom_damage, int offset, int top_damage, ptrdiff_t stride, int x,
    const uint8_t * cm, uint8_t * dst)
{
  for (x = 0; x < 8; x++)
    {
      int a, b, c, d;
      a = dst[offset + x + 7 * stride] - dst[offset + x + 6 * stride];
      b = dst[offset + x + 8 * stride] - dst[offset + x + 7 * stride];
      c = dst[offset + x + 9 * stride] - dst[offset + x + 8 * stride];
      d =
	((b) >=
	 0 ? (b) : (-(b))) - ((((a) >= 0 ? (a) : (-(a))) +
			       ((c) >= 0 ? (c) : (-(c))) + 1) >> 1);
      d = ((d) > (0) ? (d) : (0));
      if (b < 0)
	d = -d;
      if (d == 0)
	continue;
      if (!(top_damage && bottom_damage))
	d = d * 16 / 9;
      if (top_damage)
	{
	  dst[offset + x + 7 * stride] =
	    cm[dst[offset + x + 7 * stride] + ((d * 7) >> 4)];
	  dst[offset + x + 6 * stride] =
	    cm[dst[offset + x + 6 * stride] + ((d * 5) >> 4)];
	  dst[offset + x + 5 * stride] =
	    cm[dst[offset + x + 5 * stride] + ((d * 3) >> 4)];
	  dst[offset + x + 4 * stride] =
	    cm[dst[offset + x + 4 * stride] + ((d * 1) >> 4)];
	}
      if (bottom_damage)
	{
	  dst[offset + x + 8 * stride] =
	    cm[dst[offset + x + 8 * stride] - ((d * 7) >> 4)];
	  dst[offset + x + 9 * stride] =
	    cm[dst[offset + x + 9 * stride] - ((d * 5) >> 4)];
	  dst[offset + x + 10 * stride] =
	    cm[dst[offset + x + 10 * stride] - ((d * 3) >> 4)];
	  dst[offset + x + 11 * stride] =
	    cm[dst[offset + x + 11 * stride] - ((d * 1) >> 4)];
	}
    }
}

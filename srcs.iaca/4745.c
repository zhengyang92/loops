#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int y, int left_damage, int offset, ptrdiff_t stride, int right_damage,
    const uint8_t * cm, uint8_t * dst)
{
  for (y = 0; y < 8; y++)
     { IACA_START
      int a, b, c, d;
      a = dst[offset + 7 + y * stride] - dst[offset + 6 + y * stride];
      b = dst[offset + 8 + y * stride] - dst[offset + 7 + y * stride];
      c = dst[offset + 9 + y * stride] - dst[offset + 8 + y * stride];
      d =
	((b) >=
	 0 ? (b) : (-(b))) - ((((a) >= 0 ? (a) : (-(a))) +
			       ((c) >= 0 ? (c) : (-(c))) + 1) >> 1);
      d = ((d) > (0) ? (d) : (0));
      if (b < 0)
	d = -d;
      if (d == 0)
	continue;
      if (!(left_damage && right_damage))
	d = d * 16 / 9;
      if (left_damage)
	{
	  dst[offset + 7 + y * stride] =
	    cm[dst[offset + 7 + y * stride] + ((d * 7) >> 4)];
	  dst[offset + 6 + y * stride] =
	    cm[dst[offset + 6 + y * stride] + ((d * 5) >> 4)];
	  dst[offset + 5 + y * stride] =
	    cm[dst[offset + 5 + y * stride] + ((d * 3) >> 4)];
	  dst[offset + 4 + y * stride] =
	    cm[dst[offset + 4 + y * stride] + ((d * 1) >> 4)];
	}
      if (right_damage)
	{
	  dst[offset + 8 + y * stride] =
	    cm[dst[offset + 8 + y * stride] - ((d * 7) >> 4)];
	  dst[offset + 9 + y * stride] =
	    cm[dst[offset + 9 + y * stride] - ((d * 5) >> 4)];
	  dst[offset + 10 + y * stride] =
	    cm[dst[offset + 10 + y * stride] - ((d * 3) >> 4)];
	  dst[offset + 11 + y * stride] =
	    cm[dst[offset + 11 + y * stride] - ((d * 1) >> 4)];
	}
     } IACA_END
}

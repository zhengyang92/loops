#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;

int
fn (int x, uint8_t * src, const int strength, int stride)
{
  IACA_START for (x = 0; x < 8; x++)
    {
      int d1, d2, ad1;
      int p0 = src[x - 2 * stride];
      int p1 = src[x - 1 * stride];
      int p2 = src[x + 0 * stride];
      int p3 = src[x + 1 * stride];
      int d = (p0 - p3 + 4 * (p2 - p1)) / 8;
      if (d < -2 * strength)
	d1 = 0;
      else if (d < -strength)
	d1 = -2 * strength - d;
      else if (d < strength)
	d1 = d;
      else if (d < 2 * strength)
	d1 = 2 * strength - d;
      else
	d1 = 0;
      p1 += d1;
      p2 -= d1;
      if (p1 & 256)
	p1 = ~(p1 >> 31);
      if (p2 & 256)
	p2 = ~(p2 >> 31);
      src[x - 1 * stride] = p1;
      src[x + 0 * stride] = p2;
      ad1 = ((d1) >= 0 ? (d1) : (-(d1))) >> 1;
      d2 = av_clip_c ((p0 - p3) / 4, -ad1, ad1);
      src[x - 2 * stride] = p0 - d2;
      src[x + stride] = p3 + d2;
     } IACA_END
}

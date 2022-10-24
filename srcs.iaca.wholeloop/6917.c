#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int y, ptrdiff_t stride, int x, uint8_t c1[64], uint8_t * dst,
    uint8_t c0[64])
{
  IACA_START for (x = 0; x < 4; x++)
    {
      uint8_t *p = dst + x * 4 + y * stride;
      int r = c0[x * 4 + y * 16];
      int g = c1[x * 4 + y * 16];
      int b = 127;
      int d = (255 * 255 - r * r - g * g) / 2;
      if (d > 0)
	b = rint (sqrtf (d));
      p[0] = r;
      p[1] = g;
      p[2] = b;
      p[3] = 255;
     } IACA_END
}

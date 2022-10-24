#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (int w, int mxy, int x, ptrdiff_t ds, int avg, uint16_t * dst,
    const uint16_t * src)
{
  IACA_START for (x = 0; x < w; x++)
    if (avg)
      {
	dst[x] =
	  (dst[x] + (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4)) +
	   1) >> 1;
      }
    else
      {
	dst[x] = (src[x] + ((mxy * (src[x + ds] - src[x]) + 8) >> 4));
      }
}

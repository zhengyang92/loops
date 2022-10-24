#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef long int ptrdiff_t;

int
fn (int w, int mxy, int x, ptrdiff_t ds, const uint8_t * src, uint8_t * dst,
    int avg)
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

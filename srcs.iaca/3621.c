#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int w, int mxy, ptrdiff_t ds, int x, const uint8_t * src, uint8_t * dst,
    int avg)
{
  for (x = 0; x < w; x++)
  { IACA_START
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
  } IACA_END
}

#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef long int ptrdiff_t;
typedef __uint16_t uint16_t;

int
fn (const uint16_t * src, int w, int mxy, ptrdiff_t ds, int x, uint16_t * dst,
    int avg)
{
  for (x = 0; x < w; x++)
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

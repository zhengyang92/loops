#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;

int
fn (int w, int x, const uint16_t * msrc, int half, const uint16_t * asrc,
    int max, uint16_t * dst)
{
  IACA_START for (x = 0; x < w; x++)
    {
      if (asrc[x] > 0 && asrc[x] < max)
	dst[x] =
	  (((((msrc[x] - half) * max / asrc[x]) >
	     (half - 1) ? (half - 1) : ((msrc[x] - half) * max / asrc[x]))) >
	   (-half)
	   ? ((((msrc[x] - half) * max / asrc[x]) >
	       (half - 1) ? (half -
			     1) : ((msrc[x] -
				    half) * max / asrc[x]))) : (-half)) +
	  half;
      else
	dst[x] = msrc[x];
     } IACA_END
}

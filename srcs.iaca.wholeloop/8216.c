#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef long int ptrdiff_t;
typedef __uint8_t uint8_t;

int
fn (int w, ptrdiff_t ds, const int16_t * filter, int x, const uint8_t * src,
    uint8_t * dst, int avg)
{
  IACA_START for (x = 0; x < w; x++)
    if (avg)
      {
	dst[x] =
	  (dst[x] +
	   av_clip_uint8_c ((filter[0] * src[x + -3 * ds] +
			     filter[1] * src[x + -2 * ds] +
			     filter[2] * src[x + -1 * ds] +
			     filter[3] * src[x + +0 * ds] +
			     filter[4] * src[x + +1 * ds] +
			     filter[5] * src[x + +2 * ds] +
			     filter[6] * src[x + +3 * ds] +
			     filter[7] * src[x + +4 * ds] + 64) >> 7) +
	   1) >> 1;
      }
    else
      {
	dst[x] =
	  av_clip_uint8_c ((filter[0] * src[x + -3 * ds] +
			    filter[1] * src[x + -2 * ds] + filter[2] * src[x +
									   -1
									   *
									   ds]
			    + filter[3] * src[x + +0 * ds] +
			    filter[4] * src[x + +1 * ds] + filter[5] * src[x +
									   +2
									   *
									   ds]
			    + filter[6] * src[x + +3 * ds] +
			    filter[7] * src[x + +4 * ds] + 64) >> 7);
      }
}

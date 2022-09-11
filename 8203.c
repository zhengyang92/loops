#include <stdint.h>
#include <stdio.h>




typedef __uint16_t uint16_t;
typedef long int ptrdiff_t;
typedef __int16_t int16_t;

int
fn (int w, int x, ptrdiff_t ds, const int16_t * filter, int avg,
    uint16_t * dst, const uint16_t * src)
{
  for (x = 0; x < w; x++)
    if (avg)
      {
	dst[x] =
	  (dst[x] +
	   av_clip_uintp2_c ((filter[0] * src[x + -3 * ds] +
			      filter[1] * src[x + -2 * ds] +
			      filter[2] * src[x + -1 * ds] +
			      filter[3] * src[x + +0 * ds] +
			      filter[4] * src[x + +1 * ds] +
			      filter[5] * src[x + +2 * ds] +
			      filter[6] * src[x + +3 * ds] +
			      filter[7] * src[x + +4 * ds] + 64) >> 7,
			     10) + 1) >> 1;
      }
    else
      {
	dst[x] =
	  av_clip_uintp2_c ((filter[0] * src[x + -3 * ds] +
			     filter[1] * src[x + -2 * ds] +
			     filter[2] * src[x + -1 * ds] +
			     filter[3] * src[x + +0 * ds] +
			     filter[4] * src[x + +1 * ds] +
			     filter[5] * src[x + +2 * ds] +
			     filter[6] * src[x + +3 * ds] +
			     filter[7] * src[x + +4 * ds] + 64) >> 7, 10);
      }
}

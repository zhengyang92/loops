#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int w, int x, const int16_t * filter, uint8_t * tmp_ptr, uint8_t * dst,
    int avg)
{
  IACA_START for (x = 0; x < w; x++)
    if (avg)
      {
	dst[x] =
	  (dst[x] +
	   av_clip_uint8_c ((filter[0] * tmp_ptr[x + -3 * 64] +
			     filter[1] * tmp_ptr[x + -2 * 64] +
			     filter[2] * tmp_ptr[x + -1 * 64] +
			     filter[3] * tmp_ptr[x + +0 * 64] +
			     filter[4] * tmp_ptr[x + +1 * 64] +
			     filter[5] * tmp_ptr[x + +2 * 64] +
			     filter[6] * tmp_ptr[x + +3 * 64] +
			     filter[7] * tmp_ptr[x + +4 * 64] + 64) >> 7) +
	   1) >> 1;
      }
    else
      {
	dst[x] =
	  av_clip_uint8_c ((filter[0] * tmp_ptr[x + -3 * 64] +
			    filter[1] * tmp_ptr[x + -2 * 64] +
			    filter[2] * tmp_ptr[x + -1 * 64] +
			    filter[3] * tmp_ptr[x + +0 * 64] +
			    filter[4] * tmp_ptr[x + +1 * 64] +
			    filter[5] * tmp_ptr[x + +2 * 64] +
			    filter[6] * tmp_ptr[x + +3 * 64] +
			    filter[7] * tmp_ptr[x + +4 * 64] + 64) >> 7);
      }
  IACA_END
}

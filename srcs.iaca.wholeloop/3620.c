#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (const int16_t * filtery, int w, int x, uint8_t * tmp_ptr, uint8_t * dst,
    int avg)
{
  IACA_START for (x = 0; x < w; x++)
    if (avg)
      {
	dst[x] =
	  (dst[x] +
	   av_clip_uint8_c ((filtery[0] * tmp_ptr[x + -3 * 64] +
			     filtery[1] * tmp_ptr[x + -2 * 64] +
			     filtery[2] * tmp_ptr[x + -1 * 64] +
			     filtery[3] * tmp_ptr[x + +0 * 64] +
			     filtery[4] * tmp_ptr[x + +1 * 64] +
			     filtery[5] * tmp_ptr[x + +2 * 64] +
			     filtery[6] * tmp_ptr[x + +3 * 64] +
			     filtery[7] * tmp_ptr[x + +4 * 64] + 64) >> 7) +
	   1) >> 1;
      }
    else
      {
	dst[x] =
	  av_clip_uint8_c ((filtery[0] * tmp_ptr[x + -3 * 64] +
			    filtery[1] * tmp_ptr[x + -2 * 64] +
			    filtery[2] * tmp_ptr[x + -1 * 64] +
			    filtery[3] * tmp_ptr[x + +0 * 64] +
			    filtery[4] * tmp_ptr[x + +1 * 64] +
			    filtery[5] * tmp_ptr[x + +2 * 64] +
			    filtery[6] * tmp_ptr[x + +3 * 64] +
			    filtery[7] * tmp_ptr[x + +4 * 64] + 64) >> 7);
      }
  IACA_END
}

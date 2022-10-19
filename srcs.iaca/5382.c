#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint16_t uint16_t;

int
fn (const int16_t * filtery, int w, uint16_t * dst, int x, uint16_t * tmp_ptr,
    int avg)
{
  for (x = 0; x < w; x++)
    if (avg)
      {
	dst[x] =
	  (dst[x] +
	   av_clip_uintp2_c ((filtery[0] * tmp_ptr[x + -3 * 64] +
			      filtery[1] * tmp_ptr[x + -2 * 64] +
			      filtery[2] * tmp_ptr[x + -1 * 64] +
			      filtery[3] * tmp_ptr[x + +0 * 64] +
			      filtery[4] * tmp_ptr[x + +1 * 64] +
			      filtery[5] * tmp_ptr[x + +2 * 64] +
			      filtery[6] * tmp_ptr[x + +3 * 64] +
			      filtery[7] * tmp_ptr[x + +4 * 64] + 64) >> 7,
			     10) + 1) >> 1;
      }
    else
      {
	dst[x] =
	  av_clip_uintp2_c ((filtery[0] * tmp_ptr[x + -3 * 64] +
			     filtery[1] * tmp_ptr[x + -2 * 64] +
			     filtery[2] * tmp_ptr[x + -1 * 64] +
			     filtery[3] * tmp_ptr[x + +0 * 64] +
			     filtery[4] * tmp_ptr[x + +1 * 64] +
			     filtery[5] * tmp_ptr[x + +2 * 64] +
			     filtery[6] * tmp_ptr[x + +3 * 64] +
			     filtery[7] * tmp_ptr[x + +4 * 64] + 64) >> 7,
			    10);
      }
}

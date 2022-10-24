#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __int16_t int16_t;
typedef __uint8_t uint8_t;

int
fn (int x, int delta, const int16_t * weights, uint8_t * dst, uint8_t * src)
{
  IACA_START for (x = 0; x < 8; x++)
    {
      dst[x] =
	av_clip_uint8_c ((src[x - delta] * weights[0] + src[x] * weights[1] +
			  src[x + delta] * weights[2] + src[x +
							    2 * delta] *
			  weights[3] + 64) >> 7);
     } IACA_END
}

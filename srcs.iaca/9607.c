#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int x, int *t, uint8_t * src, const int16_t * h_weights)
{
  for (x = 0; x < 8; x++)
     { IACA_START
      t[x] =
	av_clip_uint8_c ((src[x - 1] * h_weights[0] + src[x] * h_weights[1] +
			  src[x + 1] * h_weights[2] + src[x +
							  2] * h_weights[3] +
			  64) >> 7);
     } IACA_END
}

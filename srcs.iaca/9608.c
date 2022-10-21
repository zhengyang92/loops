#include "../iacaMarks.h"
#include <stdint.h>
#include <stdio.h>




typedef __uint8_t uint8_t;
typedef __int16_t int16_t;

int
fn (int x, uint8_t * dst, int *t, const int16_t * v_weights)
{
  for (x = 0; x < 8; x++)
     { IACA_START
      dst[x] =
	av_clip_uint8_c ((t[x - 8] * v_weights[0] + t[x] * v_weights[1] +
			  t[x + 8] * v_weights[2] + t[x + 16] * v_weights[3] +
			  64) >> 7);
     } IACA_END
}
